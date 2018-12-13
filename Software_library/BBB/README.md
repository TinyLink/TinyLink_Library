# 基于BeagleBone Black开发平台扩充TinyLink软件库（Linux,x86_64）
## Step 1. 搭建本地BBB平台下的TinyLink环境
### 1. 下载[BBB交叉编译链](https://pan.baidu.com/s/1gP45yHg4g9zTzID6k5QmSw)并解压
### 2. 下载[BBB软件库](https://github.com/TinyLink/TinyLink_Library/tree/master/Software_library/BBB)到本地，修改CMakeLists.txt配置交叉编译链路径CMAKE_CXX_COMPILER为本地交叉编译链
## Step 2. 封装传感器驱动库（以扩充Grove Light Sensor为例）
### 1. 查阅[wiki说明](https://github.com/TinyLink/TinyLink_Library/wiki/Config_Header_File_Generation)，在表"Mapping among Device, Functionality and Module"中发现Grove Light Sensor的ID为3023，Function为Light，Module为Grove_Light。
### 2. 在TinyLink/TL_Device_ID.h添加#define GROVE_LIGHT 3023，在TinyLink/TL_Libraries.h添加:
```
#ifdef TINYLINK_LIGHT
        #if PLATFORM == 3 && BOARD == 1005
                #if TINYLINK_LIGHT == GROVE_LIGHT
                        #include "Grove_Light_Light_BBB.h"
                #endif
        #endif
#endif
```
### 3. 新建TL_LIGHT文件夹（这个名字是wiki查到的Function，需要转变为TL_+大写Function名，如果已经存在则不需要），在TL_LIGHT下新建GROVE_LIGHT（这个名字是wiki查到的Module，需要转变为大写Module名）文件夹
### 4. 在TL_LIGHT/GROVE_LIGHT文件夹下新建Grove_Light_Light_BBB.h和Grove_Light_Light_BBB.cpp，封装成API文档中TL_Light所拥有的接口。传感器模块驱动代码可在[Seeed studio](http://wiki.seeedstudio.com/)找到
## Step 3. 测试新封装的软件库
### 1. 需要开发者手动编写TL_Config.h文件，编写模板见[wiki说明](https://github.com/TinyLink/TinyLink_Library/wiki/Config_Header_File_Generation)中的TL_Config.h specification
### 2. 串口打印温度测试文件见sketch.cpp和TinyLink/TL_Config.h
### 3. 交叉编译:
```
mkdir build
cd build
cmake ..
make
```
### 4. 将bin/main远程拷贝至BBB开发板，并运行
