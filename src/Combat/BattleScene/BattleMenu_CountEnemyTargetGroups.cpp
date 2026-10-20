#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x0217538C; symbol: func_ov000_0217538c; size: 0x4c.
// Counts transitions between consecutive target group identifiers.
extern "C" int BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[];
extern "C" int BattleMenu_CountEnemyTargetGroups(unsigned char* menu) {
 int previous=-1;
 int count=0;
 for(int i=0;i<BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[1];i++) {
  int group=*(int*)(menu+0x1d1c+i*4);
  if(previous!=group) {previous=group;count++;}
  
 }
 return count;
}
