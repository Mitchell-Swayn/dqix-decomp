#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN9GameState19GetCombatantByIndexEi(void*,int);
extern "C" void Graphics_ApplyBoundPositionAndAngle(char*);
extern "C" unsigned PartySelection_GetMemberMask(unsigned char*,unsigned);
// Original: arm9/ov000 @ 0x02167DD8; symbol: func_ov000_02167dd8; size: 0x94.
extern "C" void Graphics_ApplySelectedAndIndexedCombatantTransforms(unsigned char* self) {
 void* state=_ZN9GameState11GetInstanceEv();
 for(int i=0;i<4;i++) {
  if(PartySelection_GetMemberMask(*(unsigned char**)(self+0x2a0),(unsigned char)i)) {
   char* object=_ZN9GameState19GetCombatantByIndexEi(state,i);
   if(object) Graphics_ApplyBoundPositionAndAngle(object);
  }
 }
 for(int i=0xc0;i<0xc8;i++) {
  char* object=_ZN9GameState19GetCombatantByIndexEi(state,i);
  if(object) Graphics_ApplyBoundPositionAndAngle(object);
 }
 self[0x5951]=(self[0x5951]&~3)|2;
}
