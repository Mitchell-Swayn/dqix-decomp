#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020960CC; symbol: func_020960cc; size: 0x34.
extern "C" void Quest_ClearBoundedIdFlag(void*,unsigned char* p,int bit){if(bit>204)return;if(bit<0)return;unsigned char mask=1U<<(bit&7);p[bit>>3]&=~mask;}
