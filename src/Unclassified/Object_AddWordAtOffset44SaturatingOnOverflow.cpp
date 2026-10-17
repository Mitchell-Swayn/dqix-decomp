#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x020A0840; symbol: func_020a0840; size: 0x18.
void Object_AddWordAtOffset44SaturatingOnOverflow(unsigned int *p,unsigned int v){unsigned int old=p[17];v+=old;if(v<old)v=-1;p[17]=v;}
}
