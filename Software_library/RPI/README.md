## Step 1. Config environment
Step 1. Setup cross compiling environment on Linux(x64). Modify CmakeLists.txt "SET(CMAKE_CXX_COMPILER "gcc-linaro-arm-linux-gnueabihf-raspbianPath/bin/arm-linux-gnueabihf-g++")"    
## Step 2. Cross compiling
Step 2. cd RPI && mkdir build  
Step 3. cd build && cmake ..  
Step 4. make  
## Test & run
Step 5. cd ../bin  
Step 6. scp main username@ip:  
Step 7. ssh to the mainboard. Then run ./main  
