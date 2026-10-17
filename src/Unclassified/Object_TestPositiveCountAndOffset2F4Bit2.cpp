#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
struct A{char pad[0x2ac];short count;char pad2[70];unsigned int pad3:2;unsigned int flag:1;};
// Original: arm9/main @ 0x020850D0; symbol: func_020850d0; size: 0x2C.
bool Object_TestPositiveCountAndOffset2F4Bit2(A *p){if(p->count<=0)return false;return p->flag!=0;}
}
