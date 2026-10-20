#include <globaldefs.h>
extern "C" {
struct A{char pad[0x2ac];short count;char pad2[70];unsigned int pad3:30;unsigned int flag:1;};
// Original: arm9/main @ 0x020856F4; symbol: func_020856f4; size: 0x2C.
bool CharacterState_TestActiveSpecialPrimaryModifierBit30(A *p){if(p->count<=0)return false;return p->flag!=0;}
}
