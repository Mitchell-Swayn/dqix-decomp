#pragma thumb off
#pragma always_inline on
#pragma optimization_level 2
#pragma opt_common_subs off
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
class LoadState{};typedef void(LoadState::*LoadAction)();struct ActionPair{LoadAction first,second;};
extern "C" {void Object_RemoveSingleBackgroundTaskAndMarkComplete(void*);void Object_ClearTwoStateFieldsAndOptionallyResetAnimation(void*,int);void* GetGlobalStatePointer();void SetWordMaskBits_Main020466E4(void*,int);extern char data_020f2838[];extern ActionPair data_020ee678;extern LoadAction data_020e6d5c;}
// Original: arm9/main @ 0x020D9E44; symbol: func_020d9e44; size: 0x170.
extern "C" void QueueConditionalBackgroundResourceTask(unsigned char* object){BackgroundLoader* loader=BackgroundLoader::GetInstance();if(!object[10]){if(!*(unsigned short*)(object+8))Object_RemoveSingleBackgroundTaskAndMarkComplete(object);else{Object_ClearTwoStateFieldsAndOptionallyResetAnimation(GameState::GetInstance()->GetUnknownGameObject(),1);SetWordMaskBits_Main020466E4(GetGlobalStatePointer(),30);if(*(unsigned short*)(object+8)&1)*(int*)(object+12)=loader->QueueLoadFile(data_020f2838,0);++object[10];}}else if(object[10]==1){int i;int absent=0;i=absent;for(;i<1;++i){int id=*(int*)(object+i*4+12);if(id==-1)++absent;else if(loader->GetTaskStatus(id)){if(loader->GetDetailedTaskStatus(*(int*)(object+i*4+12))==2)break;loader->RemoveTask(*(int*)(object+i*4+12));*(int*)(object+i*4+12)=-1;}}if(absent==1)object[10]=0;else if(i!=1){ActionPair actions=data_020ee678;actions.second=data_020e6d5c;LoadAction* array=(LoadAction*)&actions;(((LoadState*)object)->*array[i])();}}}
