#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN9GameState19GetCombatantByIndexEi(void*,int);
extern "C" unsigned GameObject_CollectBattleLinkedRecordsByKey(char*,unsigned,void**,unsigned);
extern "C" int GameObject_HasBattleMotionExclusionFlag80(char*);
extern "C" int Combat_GetLatestTargetFromHistory(char*);
extern "C" char* Combat_GetCommandActorSnapshot(char*,int);
extern "C" char* Combat_GetIndexedActionTarget(char*,int);
extern "C" char* BattleScene_ResolveCurrentActionRecord(void*);
extern "C" void* BattleScene_GetCurrentActionIndex(void*);
// Original: arm9/ov025 @ 0x021DFA9C; symbol: func_ov025_021dfa9c; size: 0x138.
extern "C" void* BattleScene_FindRepeatedAttackAlternateTarget(void* arg,char* base) {
 void* state=_ZN9GameState11GetInstanceEv();
 char* rec=BattleScene_ResolveCurrentActionRecord(arg);
 int index=(int)BattleScene_GetCurrentActionIndex(arg);
 char* first=Combat_GetCommandActorSnapshot(rec,0);
 if(first) {
 unsigned key=*(unsigned short*)rec;
 char* actor=_ZN9GameState19GetCombatantByIndexEi(state,*(unsigned short*)(first+0x20));
 if(actor && index>0 && key==1 && GameObject_HasBattleMotionExclusionFlag80(actor)) {
 char* other=base+0x821c+(index-1)*0x28;
 if(other) {
 char* second=Combat_GetCommandActorSnapshot(other,0);
 if(second && *(unsigned short*)(second+0x20)==*(unsigned short*)(first+0x20)) {
 char* a=Combat_GetIndexedActionTarget(rec,0);
 char* b=Combat_GetIndexedActionTarget(other,0);
 if(a && b && *(short*)(a+0xe)==*(short*)(b+0xe) && *(unsigned short*)other==1 && Combat_GetLatestTargetFromHistory(b)==*(short*)(b+0xe)) {
 void* targets[2];
 if((int)GameObject_CollectBattleLinkedRecordsByKey(actor,key,targets,2)>=2) return targets[1];
 }
 }
 }
 }
 }
 return 0;
}
