#include <globaldefs.h>
extern "C" {
struct A{char pad[0x2ac];short count;char pad2[74];unsigned int pad3:2;unsigned int flag:1;};
// Original: arm9/main @ 0x020857C0; symbol: func_020857c0; size: 0x2C.
bool TestWord2F8Bit2WhenHalfword2ACPositive(A *p){if(p->count<=0)return false;return p->flag!=0;}
}
