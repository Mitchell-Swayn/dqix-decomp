#include <globaldefs.h>
ARM
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(void*,const void*,short);
extern "C" char* FieldBattle_GetCombatContext(void*);
extern "C" char* FieldBattle_GetScene(void*);
extern "C" char* FieldBattle_GetEncounterRequest(void*);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*,int);
extern "C" char* GameObject_GetLinkedIndexedState(void*);
// Original: arm9/ov017 @ 0x021C8588; symbol: func_ov017_021c8588; size: 0xCC.
// Applies nonnegative party category/control bytes and marks the sender scene flag when the battle owner is active.
extern "C" void BattleScene_EnableFlags(void*,unsigned);
struct Flags {unsigned pad:30;unsigned controlled:1;unsigned other:1;};
extern "C" void Combat_ApplyPartyControlCategorySnapshot(unsigned sender,char* packet,void* game,char* resources) {
 char* scene;
 char* payload;
 int i;
 void* owner=*(void**)(resources+0x3718);
 scene=FieldBattle_GetScene(owner);
 if(!scene)return;
 if(!FieldBattle_GetCombatContext(owner))return;
 payload=packet+4;
 for(i=0;i<4;i++) {
 void* object=GameState_GetObjectWithFlag100(game,i);
 if(!object)continue;
 char* state=GameObject_GetLinkedIndexedState(object);
 if(!state)continue;
 signed char* control=(signed char*)payload+i;
 int category=*(signed char*)(payload+i);
 int controlled=control[4];
 if(category>=0)*(int*)(state+0x94c)=category;
 if(controlled>=0)((Flags*)(state+0x78))->controlled=(unsigned short)controlled;
 }
 if(((unsigned char*)owner)[3] && scene) BattleScene_EnableFlags(scene,0x4000000<<sender);
}
