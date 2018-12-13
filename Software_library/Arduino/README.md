# 基于Arduino（LinkIT ONE）开发平台扩充TinyLink软件库
## Step 1. 搭建本地Arduino平台下的TinyLink环境
### 1. 下载[Arduino IDE](https://www.arduino.cc/en/Main/Software)
### 2. 下载[Arduino库](https://github.com/TinyLink/TinyLink_Library/tree/master/Software_library/Arduino)到本地，将[Attention文件夹](https://github.com/TinyLink/TinyLink_Library/tree/master/Software_library/Arduino/Attention)下的WiFiEsp和mqtt拷贝至arduino-1.x.x\libraries下，将[File.cpp](https://github.com/TinyLink/TinyLink_Library/blob/master/Software_library/Arduino/Attention/Origin_SD_lib/File.cpp)覆盖arduino-1.x.x\libraries\SD\src\File.cpp
## Step 2. 封装传感器驱动库（以扩充Grove Light Sensor为例）
### 1. 查阅[wiki说明](https://github.com/TinyLink/TinyLink_Library/wiki/Config_Header_File_Generation)，在表"Mapping among Device, Functionality and Module"中发现Grove Light Sensor的ID为3023，Function为Light，Module为Grove_Light。
### 2. 在TinyLink/TL_Device_ID.h添加#define GROVE_LIGHT 3023，在TinyLink/TL_Libraries.h添加
```
#ifdef TINYLINK_LIGHT
	#if TINYLINK_LIGHT == GROVE_LIGHT
		#include "Grove_Light_Light_Arduino_UNO.h"
	#elif TINYLINK_LIGHT == GROVE_DIGITAL_LIGHT             //  该行和下一行不是Grove Light Sensor的，而是Grove Digital Light Sensor的，如果两个传感器功能相同，则需要判断一下具体模块
		#include "Grove_Digital_Light_Light_Arduino_UNO.h"    
	#endif
#endif
```
### 3. 新建TL_LIGHT文件夹（这个名字是wiki查到的Function，需要转变为TL_+大写Function名，如果已经存在则不需要），在TL_LIGHT下新建GROVE_LIGHT（这个名字是wiki查到的Module，需要转变为大写Module名）文件夹
### 4. 在TL_LIGHT/GROVE_LIGHT文件夹下新建Grove_Light_Light_Arduino_UNO.h和Grove_Light_Light_Arduino_UNO.cpp，封装成API文档中TL_Light所拥有的接口。传感器模块驱动代码可在[Seeed studio](http://wiki.seeedstudio.com/)找到
## Step 3. 测试新封装的软件库
### 1. 需要开发者手动编写TL_Config.h文件，编写模板见[wiki说明](https://github.com/TinyLink/TinyLink_Library/wiki/Config_Header_File_Generation)中的TL_Config.h specification
### 2. Grove Light Sensor的测试文件见sketch.ino和TinyLink/TL_Config.h
### 3. 在Arduino IDE下编译sketch.ino，烧写文件到开发板，打开串口查看光照值输出
