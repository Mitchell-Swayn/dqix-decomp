#include <globaldefs.h>
ARM
#pragma always_inline on
#pragma opt_propagation off
struct ThreeWords {unsigned first,second,third;};
union Pair {struct {int x,y;};long long packed;};
extern "C" {
void* _ZN9GameState11GetInstanceEv();
unsigned Resource_CountRangeAfterPrefix(void*,unsigned short*,unsigned,unsigned);
unsigned char* _ZN9GameState19GetCombatantByIndexEi(void*,int);
void Combat_StoreFormationVectorComponents(ThreeWords*,unsigned,unsigned,unsigned);
unsigned GameObject_GetBattleGridIndexOrInvalid(unsigned char*);
void BattleGrid_GetCellCoordinates(Pair*,int*);
void GameObject_SetBattleGridIndex(int,int);
void CombatantMotion_SetDestinationXZ(unsigned char*,unsigned*);
void CombatantMotion_SetDestinationHeadingFromVector(unsigned char*,unsigned*);
extern const int PlaceCombatantAtFirstUnusedGridIndex_PreferredFormationPositionOrder[],PlaceCombatantAtFirstUnusedGridIndex_AlternatePreferredFormationPositionOrder[];
extern const ThreeWords PlaceCombatantAtFirstUnusedGridIndex_FormationTransformTemplate;
}
inline int IsPartyIndex(int id) {int valid=0;if(id>=0)valid=(id<=3);return valid;}
inline int IsEightEntryIndex(int id) {return id>=0xc0 && id<=0xc7;}
// Original: arm9/ov000 @ 0x02167FB0; symbol: func_ov000_02167fb0; size: 0x194.
// Chooses the first grid index not occupied by a combatant and writes its target position and component defaults.
extern "C" void PlaceCombatantAtFirstUnusedGridIndex(char* self,unsigned char* target) {
 if(!target)return;
 void* game=_ZN9GameState11GetInstanceEv();
 unsigned short ids[16];
 int count=Resource_CountRangeAfterPrefix(*(void**)(self+0x29c),ids,16,0);
 int id=*(short*)(target+4);
 ThreeWords component;
 const int* indices;
 if(IsPartyIndex(id)) {indices=PlaceCombatantAtFirstUnusedGridIndex_PreferredFormationPositionOrder;Combat_StoreFormationVectorComponents(&component,0,0x3244,0);}
 else if(IsEightEntryIndex(id)) {indices=PlaceCombatantAtFirstUnusedGridIndex_AlternatePreferredFormationPositionOrder;Combat_StoreFormationVectorComponents(&component,0,0,0);}
 else return;
 for(int i=0;i<16;i++) {
 int index=indices[i];int used=0;
 for(int j=0;j<count;j++) {
 unsigned char* object=_ZN9GameState19GetCombatantByIndexEi(game,(short)ids[j]);
 if(object && (unsigned)index==GameObject_GetBattleGridIndexOrInvalid(object)) {used=1;break;}
 }
 if(!used) {
 Pair copy;Pair coords;
 BattleGrid_GetCellCoordinates(&coords,&index);copy=coords;
 GameObject_SetBattleGridIndex((int)target,(unsigned char)index);
 ThreeWords position=PlaceCombatantAtFirstUnusedGridIndex_FormationTransformTemplate;
 position.first=copy.x;position.third=copy.y;
 CombatantMotion_SetDestinationXZ(target,&position.first);
 CombatantMotion_SetDestinationHeadingFromVector(target,&component.first);
 break;
 }
 }
}
