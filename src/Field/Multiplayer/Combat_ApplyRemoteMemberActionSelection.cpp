#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
typedef unsigned int undefined4;
struct Selection{unsigned char a,b,c,d;signed char e;unsigned char pad;short action;unsigned short target;};
struct Flags{unsigned char enabled:1,lock:1,value:6;};
struct Packet{unsigned unknown;unsigned short encounter,member;short action;unsigned short target;signed char e;unsigned char a,b,c,d;Flags flags;signed char recipient;};
extern "C" {
void* FieldBattle_GetEncounterRequest(void*);
unsigned FieldBattle_GetScene(void*);
unsigned FieldBattle_GetCombatContext(void*);
int Network_GetLocalMemberId(char*);
GameObject* GameState_FindIndexedObjectWithFlag1000(GameState*,int);
GameObject* GameState_GetObjectWithFlag100(GameState*,int);
undefined4 GameObject_GetLinkedIndexedState(int);
void BattleHud_ApplyRemotePartySelection(unsigned char*,unsigned,Selection*);
void* BattleHud_SetPartySelectionLock(unsigned char*,unsigned,unsigned);
void CombatScene_SetPartySelectionSyncValue(void*,int,unsigned);
}
// Original: arm9/ov017 @ 0x021C68E8; symbol: Combat_ApplyRemoteMemberActionSelection; size: 0x1B4.
extern "C" void Combat_ApplyRemoteMemberActionSelection(void* unused,Packet* packet,GameState* game,unsigned char* resources,char* network){
void* lifecycle=*(void**)(resources+0x3718);unsigned char* request=(unsigned char*)FieldBattle_GetEncounterRequest(lifecycle);if(!request)return;
unsigned char* scene=(unsigned char*)FieldBattle_GetScene(lifecycle);if(!scene)return;if(!FieldBattle_GetCombatContext(lifecycle))return;
if(*(unsigned short*)(request+8)!=packet->encounter)return;
if(packet->recipient>-1&&packet->recipient!=Network_GetLocalMemberId(network)){if(packet->flags.lock)BattleHud_SetPartySelectionLock(scene,(signed char)packet->member,1);return;}
Selection selection;selection.a=packet->a;selection.b=packet->b;selection.c=packet->c;selection.d=packet->d;selection.action=packet->action;selection.e=packet->e;selection.target=packet->target;
int allowed=1;
if(selection.b!=6&&selection.a!=13){if(GameState_FindIndexedObjectWithFlag1000(game,packet->member)){GameObject* object=GameState_GetObjectWithFlag100(game,packet->member);if(object){unsigned state=GameObject_GetLinkedIndexedState((int)object);if(state){allowed=((signed char)*(unsigned*)(state+0x94c)==5);}}}}
if(allowed)BattleHud_ApplyRemotePartySelection(scene,packet->member,&selection);
CombatScene_SetPartySelectionSyncValue(scene,(signed char)packet->flags.value,packet->flags.enabled?1:0);
if(packet->flags.lock)BattleHud_SetPartySelectionLock(scene,(signed char)packet->member,1);
}
