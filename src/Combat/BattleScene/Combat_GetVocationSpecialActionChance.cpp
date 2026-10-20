#include <globaldefs.h>
ARM
class GameState { public: static GameState* GetInstance(); };
extern "C" unsigned char* GameState_GetObjectWithFlag100(GameState*, int);
struct VocationPair { short vocation; short value; };
extern "C" VocationPair CombatGetVocationSpecialActionChance_UnknownRoleInitializedBytes[];
extern "C" short CombatGetVocationSpecialActionChance_UnknownRoleInitializedBytes_Variant2[];
// Original: arm9/ov000 @ 0x02159D24; symbol: func_ov000_02159d24; size: 0x70.
// Looks up the current vocation in a terminated pair table and returns its associated value.
extern "C" int Combat_GetVocationSpecialActionChance(void*, int slot) {
 unsigned char* object=GameState_GetObjectWithFlag100(GameState::GetInstance(),slot);
 if(!object) return 0;
 for(int i=0;CombatGetVocationSpecialActionChance_UnknownRoleInitializedBytes[i].vocation!=-1;i++) {
  int vocation=*(int*)(*(unsigned char**)(object+0x150)+0x950);
  short key=CombatGetVocationSpecialActionChance_UnknownRoleInitializedBytes[i].vocation;
  if(key==vocation)
   return CombatGetVocationSpecialActionChance_UnknownRoleInitializedBytes_Variant2[i*2];
 }
 return 0;
}
