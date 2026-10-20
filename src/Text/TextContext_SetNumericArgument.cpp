#include <globaldefs.h>
// Original: arm9/main @ 0x020465C0; symbol: func_020465c0; size: 0x18.
extern "C" void TextContext_SetNumericArgument(unsigned int *p,int i,unsigned int v){if(i<0)return;if(i<16)*(unsigned int *)((char *)(p+i)+0x8b0)=v;}
