#include <globaldefs.h>
ARM
extern "C" unsigned char data_02111654[];extern "C" void _Z25DisableSpecificInterruptsj(unsigned int);
// Original: arm9/main @ 0x020C9288; symbol: func_020c9288; size: 0x48.
extern "C" void InitializeGlobalInterruptFourStateOnce() { if(*(unsigned short*)data_02111654)return;*(unsigned short*)data_02111654=1;*(unsigned int*)(data_02111654+12)=0;*(unsigned int*)(data_02111654+16)=0;_Z25DisableSpecificInterruptsj(4);*(unsigned int*)(data_02111654+8)=0;*(unsigned int*)(data_02111654+4)=0; }
