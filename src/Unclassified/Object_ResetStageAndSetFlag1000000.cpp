#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02088150; symbol: func_02088150; size: 0x5C.
extern "C" void Object_ResetStageAndSetFlag1000000(unsigned char* p){*(unsigned*)(p+20)&=~0x800000U;p[36]=0;*(unsigned*)(p+20)&=~2U;*(unsigned short*)(p+34)&=~3;*(unsigned*)(p+20)&=~2U;*(unsigned short*)(p+34)&=~3;*(unsigned*)(p+20)|=0x1000000;p[36]=4;}
