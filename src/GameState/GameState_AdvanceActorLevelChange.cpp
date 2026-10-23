#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <std_library_functions.h>
ARM
typedef unsigned undefined4;
struct LevelChangeTask {unsigned char kind,complete;char unknown02[6];unsigned char notify;signed char member;short level;unsigned vocation,experience;int taskIds[2];int phase;unsigned flags;unsigned char restore;};
extern "C" {
 GameObject* GameState_GetObjectWithFlag100(GameState*,int);
 unsigned GameObject_GetLinkedIndexedState(int);
 int GameState_ReadProtagonistObjectIndex(GameState*);
 void GameState_InitializeActorLevelChangeTask(char*);
 void GameState_ApplyVocationLevelAndLearnSpells(unsigned,unsigned,unsigned,int,unsigned,int,int,int,int);
 int Field_QueuePartyMemberEquipmentRefresh(unsigned char*,int,int,int,int);
 extern char GameState_AdvanceActorLevelChange_PathDataPrmLevelDBin[];
 extern const char* GameStateAdvanceActorLevelChange_UnknownRoleDataReferences[];
}
// Original: arm9/main @ 0x020E3C94; symbol: GameState_AdvanceActorLevelChange; size: 0x22C.
extern "C" void GameState_AdvanceActorLevelChange(LevelChangeTask* task){
 GameState* game=GameState::GetInstance();BackgroundLoader* loader=BackgroundLoader::GetInstance();GameObject* object=GameState_GetObjectWithFlag100(game,task->member);char* state=0;if(object)state=(char*)GameObject_GetLinkedIndexedState((int)object);
 char filename[80];const char* paths[2];void* growth;void* spell;unsigned growthSize,spellSize;
 if(task->phase==0){if(!object){GameState_InitializeActorLevelChangeTask((char*)task);task->complete=1;return;}
 sprintf(filename,GameState_AdvanceActorLevelChange_PathDataPrmLevelDBin,task->vocation);paths[0]=filename;paths[1]=GameStateAdvanceActorLevelChange_UnknownRoleDataReferences[1];
 for(int i=0;i<2;++i)task->taskIds[i]=loader->QueueLoadFile(paths[i],0);task->phase=1;
 }
 if(task->phase==1){for(int i=0;i<2;++i)if(!loader->GetTaskStatus(task->taskIds[i]))return;
 loader->GetLoadedFileByID(task->taskIds[0],&growth,&growthSize);loader->GetLoadedFileByID(task->taskIds[1],&spell,&spellSize);
 unsigned saved=0;if(state&&(task->flags&1))saved=*(unsigned short*)(state+0x564);
 GameState_ApplyVocationLevelAndLearnSpells(task->member,task->level,task->vocation,task->notify,task->restore,(int)growth,growthSize,(int)spell,spellSize);
 if(state){if(task->flags&1){if(task->member==GameState_ReadProtagonistObjectIndex(game))*(unsigned short*)(state+0x564)=saved;}if(task->flags&2)*(unsigned*)(state+0x138+task->vocation*4)=task->experience;if(task->flags&4)Field_QueuePartyMemberEquipmentRefresh((unsigned char*)GameResources_GetInstance(),task->member,0,0,1);}
 for(int i=0;i<2;++i)loader->RemoveTask(task->taskIds[i]);GameState_InitializeActorLevelChangeTask((char*)task);task->complete=1;
 }
}
