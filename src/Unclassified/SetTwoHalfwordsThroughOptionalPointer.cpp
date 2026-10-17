#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02042C24; symbol: func_02042c24; size: 0x18.
extern "C" void SetTwoHalfwordsThroughOptionalPointer(unsigned char* p,unsigned short a,unsigned short b) { if (*(unsigned short**)(p+0x440)) { **(unsigned short**)(p+0x440)=a; (*(unsigned short**)(p+0x440))[1]=b; } }
