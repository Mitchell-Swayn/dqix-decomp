// Original: arm9/ov025 @ 0x021EA474; symbol: Combat_QueueOpeningActionMessagesOnce; size: 0x190.
#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
struct Definition {unsigned unused[6];unsigned low:12,kind:4,high:16;};
extern "C" {
unsigned BattleScene_GetActiveInstance();
char* BattleScene_ResolveCurrentActionRecord(char*);
void* Combat_GetCommandActorSnapshot(void*,int);
void* Combat_GetIndexedActionTarget(void*,int);
void* ActionData_GetGlobalTables();
void* ActionData_FindDefinitionInPrimaryOrSecondaryTable(char*,int);
void Combat_SetQueuedMessageDuration(void*,int,unsigned short);
int Combat_AppendActionMessage(char*,unsigned short,short,int,void*,short,unsigned short);
}
extern "C" void Combat_QueueOpeningActionMessagesOnce(char* self){
if(*(unsigned*)(self+0x1c4)&1)return;
GameState* game=GameState::GetInstance();char* action=BattleScene_ResolveCurrentActionRecord((char*)BattleScene_GetActiveInstance());
if(action){char* actor=(char*)Combat_GetCommandActorSnapshot(action,0);int id=0;char* target=(char*)Combat_GetIndexedActionTarget(action,id);if(target)id=*(short*)(target+0xe);unsigned key=*(unsigned short*)action;if(key==0x92||key==0x3a1){char* object=(char*)game->GetCombatantByIndex(*(unsigned short*)(actor+0x20));if(object)id=*(short*)(*(char**)(object+0x138)+0x2a);}
Combat_AppendActionMessage(self+0x5e8,*(unsigned short*)(action+0x18),(short)id,0,0,-1,0);
if(*(unsigned short*)(action+0x18)==250){Combat_SetQueuedMessageDuration(self+0x5e8,(unsigned short)((unsigned char)self[0x738]-1),0x1130);Combat_AppendActionMessage(self+0x5e8,480,(short)id,0,0,-1,100);}
Definition* definition=(Definition*)ActionData_FindDefinitionInPrimaryOrSecondaryTable((char*)ActionData_GetGlobalTables(),*(short*)action);
if((definition&&definition->kind==2)||*(unsigned short*)action==0x5c||*(unsigned short*)action==0x67||*(unsigned short*)action==0xa0||*(unsigned short*)action==0xbf){Combat_AppendActionMessage(self+0x5e8,*(unsigned short*)(action+0x22),(short)id,0,0,-1,0);*(unsigned short*)(action+0x22)=0;}
}
*(unsigned*)(self+0x1c4)|=1;
}
