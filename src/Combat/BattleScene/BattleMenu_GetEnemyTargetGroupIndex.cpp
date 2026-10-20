#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x021753D8; symbol: func_ov000_021753d8; size: 0x54.
// Counts transitions between consecutive target group identifiers up to the selected target.
extern "C" int BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[];
extern "C" int BattleMenu_GetEnemyTargetGroupIndex(unsigned char* menu, int target) {
 int count=-1;
 int previous=-1;
 for(int i=0;i<BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[1];i++) {
  int group=*(int*)(menu+0x1d1c+i*4);
  if(previous!=group) {previous=group;count++;}
  if(target==i) break;
 }
 return count;
}
