#include <globaldefs.h>
ARM
struct Record{unsigned char id,mapped;short pad;int value;char* object;};extern "C" {void* _ZN9GameState11GetInstanceEv();int Combat_CollectEligiblePartyIds(void*,short*,int,int);int Combat_CollectPresentEnemyIndices(void*,short*,int,int);char* _ZN9GameState19GetCombatantByIndexEi(void*,int);int BattleGrid_EncodeCombatantOccupancy(int);}
// Original: arm9/ov025 @ 0x021E1048; symbol: CollectPresentCombatantsAsTwelveByteRecords; size: 0xc4.
// Combines party and enabled IDs into12-byte records for present combatants with word8 set.
extern "C" int BattleScene_CollectMotionPlanningCombatants(void* owner,Record* output){void* state=_ZN9GameState11GetInstanceEv();short ids[12];int count=0;count+=Combat_CollectEligiblePartyIds(owner,ids,12,count);count+=Combat_CollectPresentEnemyIndices(owner,ids+count,12-count,0);int n=0;for(int i=0;i<count;++i){char* object=_ZN9GameState19GetCombatantByIndexEi(state,ids[i]);if(object&&*(int*)(object+8)){output[n].id=ids[i];output[n].mapped=BattleGrid_EncodeCombatantOccupancy(ids[i]);output[n].object=object;++n;}}return n;}
