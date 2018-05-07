## Step 1. Config environment
Step 1. Setup cross compiling environment on Linux(x64). Add cross compiling tool chain path in ~/.bashrc  
Step 2. Save and close ~/.bashrc. Run arm-none-eabi-g++ --version  
## Step 2. Cross compiling
Step 3. cd BBB && mkdir build  
Step 4. cd build && cmake ..  
Step 5. make  
## Test & run
Step 6. cd ../bin  
Step 7. scp main username@ip:  
Step 8. ssh to the mainboard. Then run ./main  
