#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
struct A{char pad[0x2ac];short count;char pad2[70];unsigned int pad3:7;unsigned int flag:1;};
// Original: arm9/main @ 0x020851AC; symbol: func_020851ac; size: 0x2C.
bool TestWord2F4Bit7WhenHalfword2ACPositive(A *p){if(p->count<=0)return false;return p->flag!=0;}
}
