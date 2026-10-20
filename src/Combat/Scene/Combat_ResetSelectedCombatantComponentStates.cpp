#include <globaldefs.h>
ARM
struct Owner;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN9GameState19GetCombatantByIndexEi(void*,int);
extern "C" unsigned PartySelection_GetMemberMask(unsigned char*,unsigned);
extern "C" void CombatantMotion_EnableGridPlacementAndResetMovement(Owner*);
extern "C" void CombatantMotion_DisableSidestep(char*);
// Original: arm9/ov000 @ 0x02167F10; symbol: func_ov000_02167f10; size: 0xA0.
extern "C" void Combat_ResetSelectedCombatantComponentStates(char* self) {
void* state=_ZN9GameState11GetInstanceEv();
for(int i=0;i<4;++i) {
if(PartySelection_GetMemberMask(*(unsigned char**)(self+0x2a0),(unsigned char)i)) {
char* obj=_ZN9GameState19GetCombatantByIndexEi(state,i);
if(obj) {CombatantMotion_EnableGridPlacementAndResetMovement((Owner*)obj); CombatantMotion_DisableSidestep(obj);}
}
}
for(int i=0xc0;i<0xc8;++i) {
char* obj=_ZN9GameState19GetCombatantByIndexEi(state,i);
if(obj) {CombatantMotion_EnableGridPlacementAndResetMovement((Owner*)obj); CombatantMotion_DisableSidestep(obj);}
}
*(unsigned char*)(self+0x5951)&=~3;
}
