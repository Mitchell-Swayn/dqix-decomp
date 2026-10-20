#include <globaldefs.h>
ARM
extern "C" void System_ReadHardwareMacAddress(void*);
// Original: arm9/ov027 @ 0x021DC618; symbol: func_ov027_021dc618; size: 0x68.
// Derives beacon timing dispersion from the six-byte hardware address and shared boot seed.
extern "C" unsigned MBi_GetBeaconPeriodDispersion(void)
{
    unsigned char mac[6];
    System_ReadHardwareMacAddress(mac);
    int i=0;
    unsigned sum=0;
    for(;i<6;i++)sum+=mac[i];
    return ((sum+*(unsigned*)0x027ffc3c)*7)%20;
}
