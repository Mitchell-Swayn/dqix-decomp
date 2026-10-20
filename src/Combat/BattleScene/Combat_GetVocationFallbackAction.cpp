#include <globaldefs.h>
ARM
class GameState { public: static GameState* GetInstance(); };
extern "C" unsigned char* GameState_GetObjectWithFlag100(GameState*, int);
struct VocationPair { short vocation; short value; };
extern "C" VocationPair CombatGetVocationFallbackAction_UnknownRoleInitializedBytes[];
extern "C" short CombatGetVocationFallbackAction_UnknownRoleInitializedBytes_Variant2[];
// Original: arm9/ov000 @ 0x02159CB4; symbol: func_ov000_02159cb4; size: 0x70.
// Looks up the current vocation in a terminated pair table and returns its associated value.
extern "C" int Combat_GetVocationFallbackAction(void*, int slot) {
 unsigned char* object=GameState_GetObjectWithFlag100(GameState::GetInstance(),slot);
 if(!object) return 0;
 for(int i=0;CombatGetVocationFallbackAction_UnknownRoleInitializedBytes[i].vocation!=-1;i++) {
  int vocation=*(int*)(*(unsigned char**)(object+0x150)+0x950);
  short key=CombatGetVocationFallbackAction_UnknownRoleInitializedBytes[i].vocation;
  if(key==vocation)
   return CombatGetVocationFallbackAction_UnknownRoleInitializedBytes_Variant2[i*2];
 }
 return 0;
}
