#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x02167484; symbol: func_ov000_02167484; size: 0x70.
// Appends each of four required species not already present in the supplied list.
extern "C" short BattleSceneAppendRequiredMonsterSpecies_UnknownRoleInitializedBytes[];
extern "C" int BattleScene_AppendRequiredMonsterSpecies(short* list,int count) {
 for(int i=0;i<4;i++) {
  int j;
  for(j=0;j<count;j++) {short species=BattleSceneAppendRequiredMonsterSpecies_UnknownRoleInitializedBytes[i]; if(species==list[j]) break;}
  if(j==count) list[count++]=BattleSceneAppendRequiredMonsterSpecies_UnknownRoleInitializedBytes[i];
 }
 return count;
}
