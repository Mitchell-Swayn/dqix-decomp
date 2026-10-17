#include <globaldefs.h>
ARM
extern "C" unsigned int data_02111304[];
// Original: arm9/ov031 @ 0x02203164; symbol: func_ov031_02203164; size: 0x14.
extern "C" void func_ov031_02203164(unsigned int value) { *(unsigned int*)((char*)data_02111304[1] + 0xa4) = value; }
