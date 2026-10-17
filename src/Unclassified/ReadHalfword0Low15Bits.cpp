#include <globaldefs.h>
extern "C" {struct A{unsigned short value:15;unsigned short rest:1;};
// Original: arm9/main @ 0x020709C8; symbol: func_020709c8; size: 0x10.
unsigned int ReadHalfword0Low15Bits(A *p){return p->value;}}
