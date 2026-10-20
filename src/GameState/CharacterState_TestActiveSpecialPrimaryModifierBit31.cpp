#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
struct A{char pad[0x2ac];short count;char pad2[70];unsigned int pad3:31;unsigned int flag:1;};
// Original: arm9/main @ 0x02085720; symbol: func_02085720; size: 0x28.
bool CharacterState_TestActiveSpecialPrimaryModifierBit31(A *p){if(p->count<=0)return false;return p->flag!=0;}
}
