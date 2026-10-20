#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02095910; symbol: func_02095910; size: 0x14.
extern "C" void Quest_PrependOrderPayload(unsigned char* p,unsigned char* node) { unsigned char* old=*(unsigned char**)(p+0xa4); *(unsigned char**)(p+0xa4)=node; if (old) *(unsigned char**)(node+0x28)=old; }
