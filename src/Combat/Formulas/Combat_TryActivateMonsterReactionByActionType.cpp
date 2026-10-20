#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int GameState_ReadProtagonistObjectIndex(void*);
extern "C" void GameObject_SetCombatActivationMarker(unsigned char*,int);
extern "C" int _Z13NextRandomMaxP6Randomi(void*,int);
extern "C" int _Z17NextRandomBetweenP6Randomii(void*,int,int);
extern "C" int CombatantState_CanApplyLinkedCombatEffect(void*);
extern "C" void CombatantState_ActivateLinkedCombatEffect(char*,int);
extern "C" void Statistics_AddProtagonistActivationCount(char*,unsigned);
extern "C" int GameState_StoreStatisticsRecord(const void*);
extern "C" bool GameState_CopyStatisticsRecord(void*);
extern "C" char* Combat_FindIndexedMonsterObject(void*,int);
struct Chance { unsigned typeA:7,chanceA:7,typeB:7,chanceB:7,rest:4; };
// Original: arm9/ov024 @ 0x021EB08C; symbol: func_ov024_021eb08c; size: 0x160.
extern "C" int Combat_TryActivateMonsterReactionByActionType(char* self,int party,int index,unsigned type) {
 void* random;
 char* obj=Combat_FindIndexedMonsterObject(*(void**)(self+0x10),index);
 if(!obj) return 0;
 char* data=*(char**)(obj+0x148);
 if(!data) return 0;
 if(!(party>=0 && party<=3 ? 1:0)) return 0;
 int result;
 random=*(void**)(self+0x10);
 unsigned roll=_Z13NextRandomMaxP6Randomi(random,100);
 if(!CombatantState_CanApplyLinkedCombatEffect(*(void**)(obj+0x138))) return 0;
 int amount=_Z17NextRandomBetweenP6Randomii(random,*(unsigned char*)(data+0x28),*(unsigned char*)(data+0x29));
 result=0;
 if(type==((Chance*)(data+0x24))->typeA) {
 if(roll<((Chance*)(data+0x24))->chanceA) {
 CombatantState_ActivateLinkedCombatEffect(*(char**)(obj+0x138),(unsigned char)amount);
 GameObject_SetCombatActivationMarker((unsigned char*)obj,1);
 *(short*)(*(char**)(obj+0x138)+0x2e)=party;
 result=1;
 }
 } else if(type==((Chance*)(data+0x24))->typeB) {
 if(roll<((Chance*)(data+0x24))->chanceB) {
 CombatantState_ActivateLinkedCombatEffect(*(char**)(obj+0x138),(unsigned char)amount);
 GameObject_SetCombatActivationMarker((unsigned char*)obj,1);
 *(short*)(*(char**)(obj+0x138)+0x2e)=party;
 result=1;
 }
 }
 if(result && party==GameState_ReadProtagonistObjectIndex(_ZN9GameState11GetInstanceEv())) {
 char buffer[0xb0];
 GameState_CopyStatisticsRecord(buffer);
 Statistics_AddProtagonistActivationCount(buffer,1);
 GameState_StoreStatisticsRecord(buffer);
 }
 return result;
}
