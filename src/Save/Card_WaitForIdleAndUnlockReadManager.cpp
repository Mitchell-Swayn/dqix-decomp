#include <globaldefs.h>
ARM
extern "C" int Card_IsReadManagerIdle();extern "C" void WaitForCardReadManagerIdle();extern "C" void _Z21UnlockCardReadManagerti(unsigned short,int);
// Original: arm9/main @ 0x020D0050; symbol: func_020d0050; size: 0x28.
extern "C" void Card_WaitForIdleAndUnlockReadManager(unsigned short id){if(!Card_IsReadManagerIdle())WaitForCardReadManagerIdle();_Z21UnlockCardReadManagerti(id,2);}
