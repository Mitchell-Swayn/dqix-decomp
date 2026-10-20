#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
struct Vector3i { int x,y,z; Vector3i& operator=(const Vector3i&); }; struct Object3D { void SetScale(const Vector3i*); };
extern "C" {
struct Table {unsigned short first,count,n,m;unsigned flags;unsigned* base;unsigned char* relocBase;};
struct Stream { unsigned char data[0x14]; short index,active; int handle; void* source; };
struct Owner { unsigned char pad[0x3c]; SafeAllocator* allocators; Object3D* object; unsigned word;void* current;unsigned char pad2[0x20];int task,load,frame,otherTask;unsigned char f7c,f7d,count,active,selected,flags,f82,gap[3];short tasks[5];unsigned char gap2[0x14];unsigned char list[0x10];SafeAllocator* arrays;void* head;void* node;void* service;unsigned words[7];unsigned char nested[0x7c];unsigned a,b,c;int handle;unsigned extra;short pane,index,extra2,page,last;unsigned char state,phase,other[2],options,closed;unsigned short field;short values[8]; };
void* DisplayContext_GetGlobalInstance();void DisplayContext_IgnoreHook();void BackgroundLoader_CancelEightTasksAndResetState(void*);void ClearFourWordRecord(void*);void BestiaryDetail_ReleaseResources(Owner*);
// Original: arm9/ov014 @ 0x02186B30; symbol: func_ov014_02186b30; size: 0x98.
void BestiaryScreen_ReleaseResources(Owner* p){if(p->handle>=0){BackgroundLoader* loader=BackgroundLoader::GetInstance();loader->RemoveTask(p->handle);p->handle=-1;}void* manager=DisplayContext_GetGlobalInstance();DisplayContext_IgnoreHook();BackgroundLoader_CancelEightTasksAndResetState(manager);ClearFourWordRecord(p->list);BestiaryDetail_ReleaseResources(p);if(!p->arrays)return;for(int i=0;i<5;++i)if(p->arrays[i].GetSignedAllocator())p->arrays[i].Destroy();}
}
