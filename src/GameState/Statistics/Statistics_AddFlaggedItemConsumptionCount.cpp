#include <globaldefs.h>
ARM
struct Flags { unsigned int low:9;unsigned int value:7;unsigned int high:16; };
// Original: arm9/main @ 0x020A0504; symbol: func_020a0504; size: 0x2C.
extern "C" void Statistics_AddFlaggedItemConsumptionCount(unsigned char* p,unsigned int add) { Flags* f=(Flags*)(p+0x18);unsigned int value=add+f->value;if(value>100)value=100;f->value=value; }
