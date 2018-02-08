## 部署Raspberry_Pi library for TinyLink到电脑（Linux）。
### Step 1. 解压交叉编译链，配置CmakeLists.txt中的交叉编译链，注意每次添加新的功能或模块也要修改CmakeLists.txt中对应的INCLUDE_DIRECTORIES和ADD_EXECUTABLE
### Step 2. cd build
### Step 3. cmake ..
### Step 4. make
### Step 5. cd ../bin，把编译生成的main拷贝到Raspberry Pi运行
