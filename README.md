# Cortex-M4-QEMU-basic-calculator
This project shows how to run a basic implementation of a calculator for the Cortex-M4 assembly running in QEMU.

## Install arm-none-eabi toolchain

To install the arm-none-eabi toolchain,go to [**arm toolchain website**](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads) and download the 13.2 toolchain (For x86_64 Linux host, select **AArch32 bare-metal target (arm-none-eabi)**), which is the **arm-gnu-toolchain-13.2.rel1-x86_64-arm-none-eabi.tar.xz** file. By terminal, 
```bash
wget https://developer.arm.com/-/media/Files/downloads/gnu/13.2.rel1/binrel/arm-gnu-toolchain-13.2.rel1-x86_64-arm-none-eabi.tar.xz
```

Then untar the file by
```bash
sudo tar -xJf arm-gnu-toolchain-13.2.rel1-x86_64-arm-none-eabi.tar.xz -C /usr/share/
```
This creates the **arm-gnu-toolchain-13.2.rel1-x86_64-arm-none-eabi** folder.

Finally, create the symbolic links
```bash
sudo ln -s /usr/share/arm-gnu-toolchain-13.2.Rel1-x86_64-arm-none-eabi/bin/arm-none-eabi-gcc /usr/bin/arm-none-eabi-gcc
sudo ln -s /usr/share/arm-gnu-toolchain-13.2.Rel1-x86_64-arm-none-eabi/bin/arm-none-eabi-g++ /usr/bin/arm-none-eabi-g++
sudo ln -s /usr/share/arm-gnu-toolchain-13.2.Rel1-x86_64-arm-none-eabi/bin/arm-none-eabi-gdb /usr/bin/arm-none-eabi-gdb
sudo ln -s /usr/share/arm-gnu-toolchain-13.2.Rel1-x86_64-arm-none-eabi/bin/arm-none-eabi-size /usr/bin/arm-none-eabi-size
sudo ln -s /usr/share/arm-gnu-toolchain-13.2.Rel1-x86_64-arm-none-eabi/bin/arm-none-eabi-objcopy /usr/bin/arm-none-eabi-objcopy
sudo ln -s /usr/share/arm-gnu-toolchain-13.2.Rel1-x86_64-arm-none-eabi/bin/arm-none-eabi-ar /usr/bin/arm-none-eabi-ar
```
Verify that the installation was correct by checking the version
```bash
arm-none-eabi-gcc --version
```

Also, install the stlink-tools:
```bash
sudo apt install stlink-tools
```

## Build the libopencm3 library

From the **makefile_version** folder, run
```bash
cd libopencm3
make clean
make
```
Then, 