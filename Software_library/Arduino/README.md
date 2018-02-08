## 部署Arduino library for TinyLink到电脑（这里假设开发者已经装有Arduino IDE）。
### Step 1. 拷贝所有TL_* 文件夹到${ARDUINO_INSTALLED_DIRECTORY}/libraries。由于Arduino IDE不会自动查找自定义库文件的二级目录，需要开发者手动将所有TL_*文件夹内的二级目录下所有的*.h和*.cpp直接拷贝到TL_*文件夹下，例如把TL_LIGHT/GROVE_LIGHT下的Grove_Light_Light_Arduino_UNO.cpp和Grove_Light_Light_Arduino_UNO.h拷贝到TL_LIGHT下。
### Step 2. 拷贝"Attention"文件夹下的WiFiEsp和mqtt到${ARDUINO_INSTALLED_DIRECTORY}/libraries, 同时将"Attention"文件夹下Origin_SD_lib目录中的SD.h和File.cpp拷贝到${ARDUINO_INSTALLED_DIRECTORY}/libraries/SD/src下。
