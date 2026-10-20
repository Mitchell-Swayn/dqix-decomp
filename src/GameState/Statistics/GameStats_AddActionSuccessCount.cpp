#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020A0038; symbol: func_020a0038; size: 0x30.
extern "C" void GameStats_AddActionSuccessCount(volatile unsigned* p,unsigned n){unsigned v=n+(p[2]>>16);if(v>65535)v=65535;p[2]=(p[2]&65535)|(v<<16);}
