#include <globaldefs.h>
#pragma thumb off
#pragma optimize_for_size off
#pragma optimization_level 2
#pragma opt_common_subs off
extern "C" void System_ReadHardwareMacAddress(unsigned char*);
// Original: arm9/main @ 0x020D4B58; symbol: func_020d4b58; size: 0x90.
extern "C" unsigned short WirelessCommand_DeriveDelayFromMacAndSharedHardwareValue()
{
    unsigned char address[8];
    System_ReadHardwareMacAddress(address);
    unsigned short uVar1;
    unsigned char* pbVar3;
    int iVar2=0;
    uVar1=0;
    pbVar3=address;
    do { ++iVar2;uVar1+=*pbVar3++; } while(iVar2<6);
    uVar1+=*(volatile unsigned*)0x027ffc3c;
    unsigned short iVar3=uVar1*7;
    return (unsigned short)((int)iVar3 % 20 + 200);
}
