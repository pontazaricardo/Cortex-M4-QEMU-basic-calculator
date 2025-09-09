# Cortex-M4-QEMU-basic-calculator
This project shows how to run a basic implementation of a calculator for the Cortex-M4 assembly running in QEMU.

---
## Install latest arm toolchain

To install the latest arm toolchain, simply run
```bash
python3 python python-pip cmake arm-none-eabi-gcc arm-none-eabi-binutils arm-none-eabi-newlib git unzip
```

### Install specific arm-none-eabi toolchains

In case an specific toolchain is needed (for example, the 13.2),go to [**arm toolchain website**](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads) and download the 13.2 toolchain (For x86_64 Linux host, select **AArch32 bare-metal target (arm-none-eabi)**), which is the **arm-gnu-toolchain-13.2.rel1-x86_64-arm-none-eabi.tar.xz** file. By terminal, 
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

---
## Verification and Additional Tools

After the toolchain was installed, verify that the installation was correct by checking the version
```bash
arm-none-eabi-gcc --version
```
Also, install the stlink-tools:
```bash
sudo apt install stlink-tools
```
---
## Build the libopencm3 library

From the **makefile_version** folder, run
```bash
cd libopencm3
make clean
make
```
---
## Execute Examples

In this project, two examples are included: (1) `test_load` and (2) `test_calculator`. To run in the STM32 discovery board, inside each one of them, execute:
```bash
cd test_load
make clean
make PLATFORM=stm32
```
Then flash it to the board via
```bash
st-flash write bin/stm32f407-test.bin 0x8000000
```
In another terminal, use `pyserial-miniterm` via
```bash
pyserial-miniterm /dev/ttyUSB0 38400
```
and reset the board (if the board has two buttons, one blue and one black, press the black one). In the pyserial-miniterm window, you should see
```
-------------
Hello World.

String with two parameters: 25, 10.
-------------
```
For the `test_load` example, and 
```
====== START ======
OK ADDITION ASSEMBLY
#
OK SUBSTRACTION ASSEMBLY
#
OK MULTIPLICATION ASSEMBLY
#
-------------
Total number of cycles: 44 cycles
  - If running on QEMU, this value doesn't matter, as it changes because of the OS.
  - If running in bare metal, this value should be constant.
-------------
```
if running the `test_calculator` (which executes assembly).