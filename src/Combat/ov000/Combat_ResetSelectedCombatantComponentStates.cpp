#include <globaldefs.h>
ARM
struct Owner;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN9GameState19GetCombatantByIndexEi(void*,int);
extern "C" unsigned ToggleMaskedFlagsAtOffset34(unsigned char*,unsigned);
extern "C" void Object_ResetNestedModeAndEnableState(Owner*);
extern "C" void ClearIndirectComponentFlag4(char*);
// Original: arm9/ov000 @ 0x02167F10; symbol: func_ov000_02167f10; size: 0xA0.
extern "C" void Combat_ResetSelectedCombatantComponentStates(char* self) {
void* state=_ZN9GameState11GetInstanceEv();
for(int i=0;i<4;++i) {
if(ToggleMaskedFlagsAtOffset34(*(unsigned char**)(self+0x2a0),(unsigned char)i)) {
char* obj=_ZN9GameState19GetCombatantByIndexEi(state,i);
if(obj) {Object_ResetNestedModeAndEnableState((Owner*)obj); ClearIndirectComponentFlag4(obj);}
}
}
for(int i=0xc0;i<0xc8;++i) {
char* obj=_ZN9GameState19GetCombatantByIndexEi(state,i);
if(obj) {Object_ResetNestedModeAndEnableState((Owner*)obj); ClearIndirectComponentFlag4(obj);}
}
*(unsigned char*)(self+0x5951)&=~3;
}
