## 部署LinkIt library for TinyLink到电脑（这里假设开发者已经装有Arduino IDE，并已完成LinkIT One开发包的安装）。
### Step 1. 拷贝所有TL_* 文件夹到${ARDUINO_INSTALLED_DIRECTORY}/libraries。由于Arduino IDE不会自动查找自定义库文件的二级目录，需要开发者手动将所有TL_*文件夹内的二级目录下所有的*.h和*.cpp直接拷贝到TL_*文件夹下，例如把TL_LIGHT/GROVE_LIGHT下的Grove_Light_Light_LinkIt_One.cpp和Grove_Light_Light_LinkIt_One.h拷贝到TL_LIGHT下。
### Step 2. 将"Attention"文件夹下Origin_SD_lib目录中的LStorage.h和LStorage.cpp拷贝到.arduino15/packages/LinkItOne/hardware/arm/1.1.17/libraries/LStorage下。
