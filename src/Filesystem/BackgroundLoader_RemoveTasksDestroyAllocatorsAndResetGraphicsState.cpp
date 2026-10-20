#include <globaldefs.h>
#include <Filesystem/BackgroundLoader.h>
#include <Memory/SafeAllocator.h>
struct State {SafeAllocator* allocs;char pad[0xb8];int task1,task2;};extern "C" unsigned SystemState_GetGlobalFlags();extern "C" void SystemState_ClearFlags(unsigned,int);extern "C" void QuestMessagePanel_Initialize(State*,int);
// Original: arm9/main @ 0x0208BA54; symbol: func_0208ba54; size: 0x98.
extern "C" ARM void BackgroundLoader_RemoveTasksDestroyAllocatorsAndResetGraphicsState(State* p){BackgroundLoader* loader=BackgroundLoader::GetInstance();loader->RemoveTask(p->task1);p->task1=-1;loader->RemoveTask(p->task2);p->task2=-1;if(p->allocs)for(int i=0;i<5;i++)if(p->allocs[i].GetSignedAllocator())p->allocs[i].Destroy();SystemState_ClearFlags(SystemState_GetGlobalFlags(),1);QuestMessagePanel_Initialize(p,0);}
