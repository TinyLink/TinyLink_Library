## Step 1. Config environment
Step 1. Setup cross compiling environment on Linux(x64). Add cross compiling tool chain path in ~/.bashrc  
Step 2. Save and close ~/.bashrc. Run arm-none-eabi-g++ --version  
## Step 2. Cross compiling
Step 3. cd Mbed  
Step 4. mebd compile -t GCC_ARM -m nrf51822  
## Test & run
Step 5. copy BUILD/nrf51822/GCC_ARM/Mbed.hex to the mainboard    
