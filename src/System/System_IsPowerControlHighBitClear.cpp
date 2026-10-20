#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x020938CC; symbol: func_020938cc; size: 0x24.
bool System_IsPowerControlHighBitClear(){return ((int)(*(volatile unsigned short *)0x04000304&0x8000)>>15)!=1;}
}
