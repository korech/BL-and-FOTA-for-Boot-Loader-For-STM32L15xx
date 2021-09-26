# BL-and-FOTA-for-STM32L15xx
Firmware Update Over The Air (FOTA) using ST built in boot loader

The code provides the small increment to be added to a another bare metal source code, in order to enable firmware update over the air, with 2 copies of the firmware at any given time (to enable recovery in case of transfer fail) which is based on ST build in boot loader.

The documentation is partly in Hebrew

Using ST Built in boot loader has some limitations on the range of usable memory.
This limitation is usually not important, but it was relevant for Meprolight, hence I wrote a revised code, which is not based on ST built in BL.
The revised code details are proprietary, hence I will only mention the main points for such a code:
- Compilation should be done in ROPI (Read Only Position Independent) Mode
- The default system reset function, which is written by default in assembly, should be re-written in c for ROPI to work correctly also on this function.
- System init should prepare a jump function to jump to the releveant one out of two versions of the code, according to EEPROM configurations which are written during FOTA.
- During the FOTA, the values of the binary code that corresponds to NVIC (Interrupt address Table) table, should be offested by the offest that corresponds to the code locations, such that the NVIC values will point on the correct address.
