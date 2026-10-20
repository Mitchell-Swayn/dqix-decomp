#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
struct Triple {unsigned x,y,z;};
extern "C" Triple CombatantMotion_GetHomePosition(char*);
extern "C" int Combat_CollectGroupIndicesByDescriptorFlags(char*,short*,int,unsigned);
extern "C" short Combat_FindEligibleEnemyWithLeastHomeX_CombatantSelectionInitialIds[];
// Original: arm9/ov000 @ 0x0215CDA0; symbol: Combat_FindEligibleEnemyWithLeastHomeX; size: 0xE0.
// Chooses the minimum X coordinate among collected combatants; selected ID <=0 resets the comparison.
extern "C" int Combat_FindEligibleEnemyWithLeastHomeX(char* self) {
 struct IndexSet {short values[8];};
 IndexSet set=*(IndexSet*)Combat_FindEligibleEnemyWithLeastHomeX_CombatantSelectionInitialIds;

 int best=-1;
 int count=Combat_CollectGroupIndicesByDescriptorFlags(self,set.values,8,1);
 Vector3i bestPosition;
 for(int i=0;i<count;i++) {
  short id=set.values[i];
  GameState* state=GameState::GetInstance();
  GameObject* object=state->GetCombatantByIndex(id);
  if(!object)continue;
  Triple current=CombatantMotion_GetHomePosition((char*)object);
  if(best>0){if((int)current.x>=bestPosition.x)continue;bestPosition=*(Vector3i*)&current;best=set.values[i];}
  else {best=set.values[i];bestPosition=*(Vector3i*)&current;}
 }
 return best;
}
