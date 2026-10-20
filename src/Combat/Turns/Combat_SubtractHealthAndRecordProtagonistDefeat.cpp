#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define I(p,o) (*(int*)((p)+(o)))
#define U(p,o) (*(unsigned*)((p)+(o)))
#define H(p,o) (*(unsigned short*)((p)+(o)))
#define S(p,o) (*(short*)((p)+(o)))
#define B(p,o) (*(unsigned char*)((p)+(o)))
#define C(p,o) (*(signed char*)((p)+(o)))
#define V(p,o) (*(char**)((p)+(o)))
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" char* _ZN9GameState19GetCombatantByIndexEi(void*,int);extern "C" void Combat_RecordMonsterDefeatSnapshot(void*,int,int,int,unsigned char,int);extern "C" void CombatantState_ResetStatusesForDefeat(unsigned char*);extern "C" void Combat_RecordMonsterDefeatAndRewards(void*,int,int);extern "C" int GameState_ReadProtagonistObjectIndex(void*);extern "C" bool GameState_CopyStatisticsRecord(void*);extern "C" void Statistics_AddProtagonistDefeatCount(unsigned char*,unsigned);extern "C" void Statistics_AddCompactProtagonistDefeatCount(char*,unsigned);extern "C" int GameState_StoreStatisticsRecord(const void*);
// Original: arm9/ov000 @ 0x0215A004; symbol: Combat_SubtractHealthAndRecordProtagonistDefeat; size: 0x120.
extern "C" int Combat_SubtractHealthAndRecordProtagonistDefeat(void* context,int source,int target,int damage,unsigned* flags,int reason,unsigned char notify,int extra){
int health;char* object=_ZN9GameState19GetCombatantByIndexEi(_ZN9GameState11GetInstanceEv(),target);if(!object)return 0;health=H(V(object,0x138),0)-damage;if(health<=0){health=0;flags[0]=0;flags[1]=0;*(unsigned long long*)flags|=4ULL;Combat_RecordMonsterDefeatSnapshot(context,target,source,reason,notify,extra);((void(*)(unsigned char*,signed char))CombatantState_ResetStatusesForDefeat)((unsigned char*)V(object,0x138),(signed char)S(object,4));Combat_RecordMonsterDefeatAndRewards(context,target,extra);if(target==GameState_ReadProtagonistObjectIndex(_ZN9GameState11GetInstanceEv())){struct Saved{unsigned char first[104],second[72];};Saved saved;GameState_CopyStatisticsRecord(&saved);Statistics_AddProtagonistDefeatCount(saved.first,1);Statistics_AddCompactProtagonistDefeatCount((char*)saved.second,1);GameState_StoreStatisticsRecord(&saved);}}if(damage>0){*(unsigned long long*)flags|=2ULL;}H(V(object,0x138),0)=health;return (short)health;
}
