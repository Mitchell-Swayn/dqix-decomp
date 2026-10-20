#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02048C68; symbol: func_02048c68; size: 0x28.
extern "C" bool GameObject_IsBattleIdleMotionSuppressed(unsigned char* p) { unsigned char* q=*(unsigned char**)(p+0x13c); if (!q) return false; return (*(unsigned int*)(q+0x20)&0x100)!=0; }
