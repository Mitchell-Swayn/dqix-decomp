#pragma thumb off
#pragma always_inline on
#pragma optimization_level 2
#pragma opt_common_subs off
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
class LoadState{};typedef void(LoadState::*LoadAction)();struct ActionPair{LoadAction first,second;};
// Original data: arm9/main @ 0x20e6d5c; symbol: data_020e6d5c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20ee678; symbol: data_020ee678.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 74a00d02000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {void Resource_RemoveSingleBackgroundTaskAndMarkComplete(void*);void GameObject_DisableMovementInput(void*,int);void* SystemState_GetGlobalFlags();void SystemState_SetFlags(void*,int);extern char Resource_QueueConditionalBackgroundResourceTask_PathDataScenarioQuestcancelBin[];extern ActionPair ResourceQueueConditionalBackgroundResourceTask_UnknownRoleProcedureReferenceRecords;extern LoadAction ShopUpdateInterface_UnknownRoleInitializedBytes;}
// Original: arm9/main @ 0x020D9E44; symbol: func_020d9e44; size: 0x170.
extern "C" void Resource_QueueConditionalBackgroundResourceTask(unsigned char* object){BackgroundLoader* loader=BackgroundLoader::GetInstance();if(!object[10]){if(!*(unsigned short*)(object+8))Resource_RemoveSingleBackgroundTaskAndMarkComplete(object);else{GameObject_DisableMovementInput(GameState::GetInstance()->GetUnknownGameObject(),1);SystemState_SetFlags(SystemState_GetGlobalFlags(),30);if(*(unsigned short*)(object+8)&1)*(int*)(object+12)=loader->QueueLoadFile(Resource_QueueConditionalBackgroundResourceTask_PathDataScenarioQuestcancelBin,0);++object[10];}}else if(object[10]==1){int i;int absent=0;i=absent;for(;i<1;++i){int id=*(int*)(object+i*4+12);if(id==-1)++absent;else if(loader->GetTaskStatus(id)){if(loader->GetDetailedTaskStatus(*(int*)(object+i*4+12))==2)break;loader->RemoveTask(*(int*)(object+i*4+12));*(int*)(object+i*4+12)=-1;}}if(absent==1)object[10]=0;else if(i!=1){ActionPair actions=ResourceQueueConditionalBackgroundResourceTask_UnknownRoleProcedureReferenceRecords;actions.second=ShopUpdateInterface_UnknownRoleInitializedBytes;LoadAction* array=(LoadAction*)&actions;(((LoadState*)object)->*array[i])();}}}
