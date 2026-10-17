#include <globaldefs.h>
#include <Filesystem/BackgroundLoader.h>
#include <Memory/SafeAllocator.h>
struct State {SafeAllocator* allocs;char pad[0xb8];int task1,task2;};extern "C" unsigned GetGlobalStatePointer();extern "C" void RecordFlags_ClearWordMask(unsigned,int);extern "C" void InitializeGraphicsStateAndEmbeddedResources(State*,int);
// Original: arm9/main @ 0x0208BA54; symbol: func_0208ba54; size: 0x98.
extern "C" ARM void BackgroundLoader_RemoveTwoTasksAndDestroyFiveAllocators(State* p){BackgroundLoader* loader=BackgroundLoader::GetInstance();loader->RemoveTask(p->task1);p->task1=-1;loader->RemoveTask(p->task2);p->task2=-1;if(p->allocs)for(int i=0;i<5;i++)if(p->allocs[i].GetSignedAllocator())p->allocs[i].Destroy();RecordFlags_ClearWordMask(GetGlobalStatePointer(),1);InitializeGraphicsStateAndEmbeddedResources(p,0);}
