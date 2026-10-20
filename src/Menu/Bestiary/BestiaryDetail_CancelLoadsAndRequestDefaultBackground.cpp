#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
struct Vector3i { int x,y,z; Vector3i& operator=(const Vector3i&); }; struct Object3D { void SetScale(const Vector3i*); };
extern "C" {
struct Table {unsigned short first,count,n,m;unsigned flags;unsigned* base;unsigned char* relocBase;};
struct Stream { unsigned char data[0x14]; short index,active; int handle; void* source; };
struct Owner { unsigned char pad[0x3c]; SafeAllocator* allocators; Object3D* object; unsigned word;void* current;unsigned char pad2[0x20];int task,load,frame,otherTask;unsigned char f7c,f7d,count,active,selected,flags,f82,gap[3];short tasks[5];unsigned char gap2[0x14];unsigned char list[0x10];SafeAllocator* arrays;void* head;void* node;void* service;unsigned words[7];unsigned char nested[0x80];unsigned a,b,c;int handle;unsigned extra;short pane,index,extra2,page,last;unsigned char state,phase,other[2],options,closed;unsigned short field;short values[8]; };
int BestiaryHabitat_CancelLoad(Stream*);
// Original: arm9/ov014 @ 0x02184D08; symbol: func_ov014_02184d08; size: 0xC4.
void BestiaryDetail_CancelLoadsAndRequestDefaultBackground(Owner* p){BackgroundLoader* loader=BackgroundLoader::GetInstance();if(p->flags&1){p->flags&=~1;if(p->task>=0){loader->RemoveTask(p->task);p->task=-1;}for(int i=0;i<5;++i){short task=p->tasks[i];if(task>=0){BackgroundLoader::GetInstance()->RemoveTask(task);p->tasks[i]=-1;}}BestiaryHabitat_CancelLoad((Stream*)((unsigned char*)p+0x1c));p->active=0;}if(p->flags&0x10)return;p->flags|=0x10;if(p->load>=0){loader->RemoveTask(p->load);p->load=-1;}p->count=0;}
}
