/* mbed Microcontroller Library
 * Copyright (c) 2006-2013 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifdef YOTTA_CFG_MBED_OS
    #include "mbed-drivers/mbed.h"
#else
    #include "mbed.h"
#endif
#include "nRF5xn.h"
#include "ble/blecommon.h"
#include "nrf_soc.h"

#include "btle/btle.h"
#include "nrf_delay.h"

extern "C" {
#include "softdevice_handler.h"
}

/**
 * The singleton which represents the nRF51822 transport for the BLE.
 */
static nRF5xn deviceInstance;

/**
 * BLE-API requires an implementation of the following function in order to
 * obtain its transport handle.
 */
BLEInstanceBase *
createBLEInstance(void)
{
    return &nRF5xn::Instance(BLE::DEFAULT_INSTANCE);
}

nRF5xn& nRF5xn::Instance(BLE::InstanceID_t instanceId)
{
    return deviceInstance;
}

nRF5xn::nRF5xn(void) :
    initialized(false),
    instanceID(BLE::DEFAULT_INSTANCE),
    gapInstance(),
    gattServerInstance(NULL),
    gattClientInstance(NULL),
    securityManagerInstance(NULL)
{
}

nRF5xn::~nRF5xn(void)
{
}

const char *nRF5xn::getVersion(void)
{
    if (!initialized) {
        return "INITIALIZATION_INCOMPLETE";
    }

    static char versionString[32];
    static bool versionFetched = false;

    if (!versionFetched) {
        ble_version_t version;
        if ((sd_ble_version_get(&version) == NRF_SUCCESS) && (version.company_id == 0x0059)) {
            switch (version.version_number) {
                case 0x07:
                case 0x08:
                    snprintf(versionString, sizeof(versionString), "Nordic BLE4.1 ver:%u fw:%04x", version.version_number, version.subversion_number);
                    break;
                default:
                    snprintf(versionString, sizeof(versionString), "Nordic (spec unknown) ver:%u fw:%04x", version.version_number, version.subversion_number);
                    break;
            }
            versionFetched = true;
        } else {
            strncpy(versionString, "unknown", sizeof(versionString));
        }
    }

    return versionString;
}

/**************************************************************************/
/*!
    @brief  Initialize the BLE stack.

    @returns    ble_error_t

    @retval     BLE_ERROR_NONE if everything executed properly and
                BLE_ERROR_ALREADY_INITIALIZED if the stack has already
                been initialized (possibly through a call to nRF5xn::init()).
                BLE_ERROR_INTERNAL_STACK_FAILURE is returned if initialization
                of the internal stack (SoftDevice) failed.

*/
/**************************************************************************/
ble_error_t nRF5xn::init(BLE::InstanceID_t instanceID, FunctionPointerWithContext<BLE::InitializationCompleteCallbackContext *> callback)
{
    if (initialized) {
        BLE::InitializationCompleteCallbackContext context = {
            BLE::Instance(instanceID),
            BLE_ERROR_ALREADY_INITIALIZED
        };
        callback.call(&context);
        return BLE_ERROR_ALREADY_INITIALIZED;
    }

    instanceID   = instanceID;

    /* ToDo: Clear memory contents, reset the SD, etc. */
    if (btle_init() != ERROR_NONE) {
        return BLE_ERROR_INTERNAL_STACK_FAILURE;
    }

    initialized = true;
    BLE::InitializationCompleteCallbackContext context = {
        BLE::Instance(instanceID),
        BLE_ERROR_NONE
    };
    callback.call(&context);
    return BLE_ERROR_NONE;
}

/**************************************************************************/
/*!
    @brief  Purge the BLE stack of GATT and GAP state.

    @returns    ble_error_t

    @retval     BLE_ERROR_NONE
                Everything executed properly

    @note  When using S110, GattClient::shutdown() will not be called
           since Gatt client features are not supported.
*/
/**************************************************************************/
ble_error_t nRF5xn::shutdown(void)
{
    if (!initialized) {
        return BLE_ERROR_INITIALIZATION_INCOMPLETE;
    }

    /*
     * Shutdown the SoftDevice first. This is because we need to disable all
     * interrupts. Otherwise if we clear the BLE API and glue code first there
     * will be many NULL references and no config information which could lead
     * to errors if the shutdown process is interrupted.
     */
    if (softdevice_handler_sd_disable() != NRF_SUCCESS) {
        return BLE_STACK_BUSY;
    }


    /* Shutdown the BLE API and nRF51 glue code */
    ble_error_t error;

    if (gattServerInstance != NULL) {
        error = gattServerInstance->reset();
        if (error != BLE_ERROR_NONE) {
            return error;
        }
    }

    if (securityManagerInstance != NULL) {
        error = securityManagerInstance->reset();
        if (error != BLE_ERROR_NONE) {
            return error;
        }
    }

    /* S110 does not support BLE client features, nothing to reset. */
#if !defined(TARGET_MCU_NRF51_16K_S110) && !defined(TARGET_MCU_NRF51_32K_S110)
    if (gattClientInstance != NULL) {
        error = gattClientInstance->reset();
        if (error != BLE_ERROR_NONE) {
            return error;
        }
    }
#endif

    /* Gap instance is always present */
    error = gapInstance.reset();
    if (error != BLE_ERROR_NONE) {
        return error;
    }

    initialized = false;
    return BLE_ERROR_NONE;
}

void
nRF5xn::waitForEvent(void)
{
	sd_app_evt_wait();
    processEvents();
}

void nRF5xn::processEvents() {
    if (isEventsSignaled) {
        isEventsSignaled = false;
        intern_softdevice_events_execute();
    }
}
