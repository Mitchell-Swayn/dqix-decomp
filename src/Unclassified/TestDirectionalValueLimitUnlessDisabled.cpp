#include <globaldefs.h>
extern "C" {
struct A{char pad[20];unsigned int flags;char pad2[64];unsigned int rest:27;signed int value:3;};
// Original: arm9/main @ 0x02087F24; symbol: func_02087f24; size: 0x54.
bool TestDirectionalValueLimitUnlessDisabled(A *p,int negative){if(p->flags&1)return false;if(!negative){if(p->value<2)return true;}else if(-2<p->value)return true;return false;}
}
