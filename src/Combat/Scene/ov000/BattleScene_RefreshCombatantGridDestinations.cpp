#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
union Pair { struct {int x,y;}; long long packed; };
struct TargetPosition {unsigned values[3];};
extern "C" TargetPosition BattleScene_RefreshCombatantGridDestinations_FormationTransformTemplate;
extern "C" unsigned Resource_CountRangeAfterPrefix(void*,unsigned short*,unsigned,unsigned);
extern "C" unsigned GameObject_GetBattleGridIndexOrInvalid(unsigned char*);
extern "C" void BattleGrid_GetCellCoordinates(Pair*,int*);
extern "C" void CombatantMotion_SetDestinationXZ(unsigned char*,unsigned*);
// Original: arm9/ov000 @ 0x02168144; symbol: BattleScene_RefreshCombatantGridDestinations; size: 0xB4.
// Computes grid coordinates for collected combatant indices and writes their nested target X/Z fields.
extern "C" void BattleScene_RefreshCombatantGridDestinations(char* self) {
 GameState* state=GameState::GetInstance();
 unsigned short ids[12];
 int count=Resource_CountRangeAfterPrefix(*(void**)(self+0x29c),ids,12,0);
 for(int i=0;i<count;++i) {
  GameObject* object=state->GetCombatantByIndex((short)ids[i]);
  if(!object)continue;
  TargetPosition position;
  Pair copy,coordinates;
  int index=GameObject_GetBattleGridIndexOrInvalid((unsigned char*)object);
  BattleGrid_GetCellCoordinates(&coordinates,&index);
  position=BattleScene_RefreshCombatantGridDestinations_FormationTransformTemplate;
  copy=coordinates;
  position.values[0]=copy.x;position.values[2]=copy.y;
  CombatantMotion_SetDestinationXZ((unsigned char*)object,position.values);
 }
}
