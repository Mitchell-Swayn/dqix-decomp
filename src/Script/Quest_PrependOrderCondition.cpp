#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020958FC; symbol: func_020958fc; size: 0x14.
extern "C" void Quest_PrependOrderCondition(unsigned char* p,unsigned char* node) { unsigned char* old=*(unsigned char**)(p+0xa0); *(unsigned char**)(p+0xa0)=node; if (old) *(unsigned char**)(node+0xc)=old; }
