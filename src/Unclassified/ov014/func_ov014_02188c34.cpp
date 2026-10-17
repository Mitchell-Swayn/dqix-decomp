#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
struct Vector3i { int x,y,z; Vector3i& operator=(const Vector3i&); }; struct Object3D { void SetScale(const Vector3i*); };
extern "C" {
struct Table {unsigned short first,count,n,m;unsigned flags;unsigned* base;unsigned char* relocBase;};
struct Stream { unsigned char data[0x14]; short index,active; int handle; void* source; };
struct Owner { unsigned char pad[0x3c]; SafeAllocator* allocators; Object3D* object; unsigned word;void* current;unsigned char pad2[0x20];int task,load,frame,otherTask;unsigned char f7c,f7d,count,active,selected,flags,f82,gap[3];short tasks[5];unsigned char gap2[0x14];unsigned char list[0x10];SafeAllocator* arrays;void* head;void* node;void* service;unsigned words[7];unsigned char nested[0x80];unsigned a,b,c;int handle;unsigned extra;short pane,index,extra2,page,last;unsigned char state,phase,other[2],options,closed;unsigned short field;short values[8]; };
extern const char* data_ov014_021897c4[2];void func_ov014_02188d48(Stream*,void*,void*,unsigned,int);int func_ov014_02188d10(Stream*);
// Original: arm9/ov014 @ 0x02188C34; symbol: func_ov014_02188c34; size: 0xDC.
int func_ov014_02188c34(Stream* p){BackgroundLoader* loader=BackgroundLoader::GetInstance();switch(p->active){case 1:p->handle=loader->QueueLoadFileInGP2(data_ov014_021897c4[1],data_ov014_021897c4[0],0);p->active=2;return func_ov014_02188c34(p);case 2:if(!loader->GetTaskStatus(p->handle))return 0;p->active=3;return func_ov014_02188c34(p);case 3:{void* data=0;unsigned length=0;loader->GetLoadedFileByID(p->handle,&data,&length);func_ov014_02188d48(p,p->source,data,length,p->index);func_ov014_02188d10(p);return 1;}default:return 1;}}
}
