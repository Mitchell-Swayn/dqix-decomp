#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
struct Task {int a;char b[4];int id;};
struct Owner {SafeAllocator* allocator;unsigned int word;char pad[4];unsigned char flags[4];unsigned int pad10;Task tasks[4];};
extern "C" void ActorEffectLoader_RemoveCurrentResources(Owner*);
extern "C" void ActorEffectLoader_ReleaseCompletedRequest(Task*);
// Original: arm9/main @ 0x020DA244; symbol: func_020da244; size: 0xA0.
extern "C" ARM void ResourceLoader_RemoveFourTasksAndDestroyAllocator(Owner* self) {
 ActorEffectLoader_RemoveCurrentResources(self);
 Task* task=self->tasks;
 BackgroundLoader* loader=BackgroundLoader::GetInstance();
 if(loader) {
  unsigned char i=0;
  while(i<4) {
   if(task->id!=-1){loader->RemoveTask(task->id!=-1);ActorEffectLoader_ReleaseCompletedRequest(task);}
   ++i;
   ++task;
  }
 }
 if(self->allocator){self->allocator->Destroy();self->allocator->ResetAllocatorPointer();}
 self->allocator=0;self->word=0;
 self->flags[0]=0;self->flags[1]=0;self->flags[2]=0;self->flags[3]=0;
}
