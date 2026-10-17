#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x020E29A8; symbol: func_020e29a8; size: 0x10.
void Object_SetByte16ClampedToTwo(char *p,int v){if(v>=3)v=2;p[22]=v;}
}
