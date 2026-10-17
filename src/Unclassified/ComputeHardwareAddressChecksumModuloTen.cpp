#include <globaldefs.h>
#pragma optimize_for_size off
extern "C" void System_ReadHardwareMacAddress(void*);
// Original: arm9/main @ 0x020D4BE8; symbol: func_020d4be8; size: 0x94.
extern "C" ARM unsigned short ComputeHardwareAddressChecksumModuloTen() {
    unsigned char address[6];
    System_ReadHardwareMacAddress(address);
    int i = 0;
    unsigned char* byte = address;
    unsigned short sum = 0;
    do { sum += *byte++; ++i; } while (i < 6);
    sum += *(volatile unsigned*)0x027ffc3c;
    sum *= 13;
    return (int)sum % 10 + 30;
}
