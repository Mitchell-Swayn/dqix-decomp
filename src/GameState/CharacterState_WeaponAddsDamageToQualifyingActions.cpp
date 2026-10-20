#include <globaldefs.h>
extern "C" {
struct A{char pad[0x2ac];short count;char pad2[70];unsigned int pad3:4;unsigned int flag:1;};
// Original: arm9/main @ 0x02085128; symbol: func_02085128; size: 0x2C.
bool CharacterState_WeaponAddsDamageToQualifyingActions(A *p){if(p->count<=0)return false;return p->flag!=0;}
}
