#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
struct Packet{unsigned unknown;unsigned short encounter,field;unsigned value;unsigned char members;signed char party;unsigned char phase,monsters;signed char optional;unsigned char padding;short position;};
extern "C" {
void* FieldBattle_GetEncounterRequest(void*);
unsigned FieldBattle_GetScene(void*);
unsigned FieldBattle_GetCombatContext(void*);
int GameState_ReadProtagonistObjectIndex(GameState*);
void BattleScene_EnableFlags(unsigned char*,unsigned);
void BattleScene_SetSynchronizedPhaseAndMonsterMask(void*,unsigned char,unsigned char);
void GameState_BeginEnabledPartySelectionTransition(unsigned char*,signed char*,int,int,unsigned short,signed char,int,int);
}
// Original: arm9/ov017 @ 0x021CBCC0; symbol: Combat_ApplyEncounterTransitionSelection; size: 0x10C.
extern "C" void Combat_ApplyEncounterTransitionSelection(void* unused,Packet* packet,GameState* game,unsigned char* resources){
unsigned char* request;unsigned value;unsigned char phase,monsters;unsigned char* lifecycle=*(unsigned char**)(resources+0x3718);request=(unsigned char*)FieldBattle_GetEncounterRequest(lifecycle);if(!request)return;
unsigned char* context=(unsigned char*)FieldBattle_GetCombatContext(lifecycle);if(!context)return;
unsigned char* scene=(unsigned char*)FieldBattle_GetScene(lifecycle);if(!scene)return;
value=packet->value;phase=packet->phase;monsters=packet->monsters;
if(packet->encounter!=*(unsigned short*)(request+8))return;
BattleScene_EnableFlags(scene,0x80000000);
int protagonist=GameState_ReadProtagonistObjectIndex(game);if(!(packet->members&(1<<protagonist)))return;
context[0x8e48]=value;BattleScene_SetSynchronizedPhaseAndMonsterMask(scene,phase,monsters);
signed char enabled[4]={0};for(int i=0;i<4;++i){if(packet->members&(1<<i))enabled[i]=1;else enabled[i]=0;}
GameState_BeginEnabledPartySelectionTransition(lifecycle,enabled,packet->party,1,packet->field,packet->optional,1,packet->position);
}
