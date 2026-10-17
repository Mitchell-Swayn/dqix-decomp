#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
struct Vector3i { int x,y,z; Vector3i& operator=(const Vector3i&); }; struct Object3D { void SetScale(const Vector3i*); };
extern "C" {
struct Table {unsigned short first,count,n,m;unsigned flags;unsigned* base;unsigned char* relocBase;};
struct Stream { unsigned char data[0x14]; short index,active; int handle; void* source; };
struct Owner { unsigned char pad[0x3c]; SafeAllocator* allocators; Object3D* object; unsigned word;void* current;unsigned char pad2[0x20];int task,load,frame,otherTask;unsigned char f7c,f7d,count,active,selected,flags,f82,gap[3];short tasks[5];unsigned char gap2[0x14];unsigned char list[0x10];SafeAllocator* arrays;void* head;void* node;void* service;unsigned words[7];unsigned char nested[0x7c];unsigned a,b,c;int handle;unsigned extra;short pane,index,extra2,page,last;unsigned char state,phase; signed char other[2];unsigned char options,closed;unsigned short field;short values[8]; };
void* memset(void*,int,unsigned);void func_ov014_021844c4(void*);void ClearWordAndTwelveByteBlock(void*);void ClearRecordAndInvalidateTwoIndices(void*);void InitializeRecordBuffersAndEnabledByte(void*);void Object_InitializeOptionalRecordAndByteDefaults(void*,void*);
// Original: arm9/ov014 @ 0x02186A70; symbol: func_ov014_02186a70; size: 0xC0.
void func_ov014_02186a70(Owner* p){func_ov014_021844c4(p);ClearWordAndTwelveByteBlock(p->list);p->arrays=0;p->head=0;p->node=0;p->service=0;p->words[0]=0;p->words[1]=0;p->words[2]=0;p->words[3]=0;p->words[4]=0;p->words[5]=0;p->words[6]=0;ClearRecordAndInvalidateTwoIndices((unsigned char*)p+0xe0);InitializeRecordBuffersAndEnabledByte((unsigned char*)p+0xf8);Object_InitializeOptionalRecordAndByteDefaults((unsigned char*)p+0x14c,(unsigned char*)p+0x158);p->a=0;p->b=0;p->c=0;p->handle=-1;p->pane=-1;p->index=-1;p->extra2=-1;p->page=-1;p->last=-1;p->state=0;p->phase=0;p->other[0]=0;p->other[1]=-1;p->options=0;p->closed=0;p->field=0;memset(p->values,0,16);}
}
