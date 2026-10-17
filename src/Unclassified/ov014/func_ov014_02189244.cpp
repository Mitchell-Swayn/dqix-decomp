#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
struct Vector3i { int x,y,z; Vector3i& operator=(const Vector3i&); }; struct Object3D { void SetScale(const Vector3i*); };
extern "C" {
struct Table {unsigned short first,count,n,m;unsigned flags;unsigned* base;unsigned char* relocBase;};
struct Stream { unsigned char data[0x14]; short index,active; int handle; void* source; };
struct Owner { unsigned char pad[0x3c]; SafeAllocator* allocators; Object3D* object; unsigned word;void* current;unsigned char pad2[0x20];int task,load,frame,otherTask;unsigned char f7c,f7d,count,active,selected,flags,f82,gap[3];short tasks[5];unsigned char gap2[0x14];unsigned char list[0x10];SafeAllocator* arrays;void* head;void* node;void* service;unsigned words[7];unsigned char nested[0x7c];unsigned a,b,c;int handle;unsigned extra;short pane,index,extra2,page,last;unsigned char state,phase,other[2],options,closed;unsigned short field;short values[8]; };
void* memcpy(void*,const void*,unsigned);unsigned func_ov014_0218934c(Table*);int func_ov014_021891f0(Table*,void (*)(Table*,unsigned*));
// Original: arm9/ov014 @ 0x02189244; symbol: func_ov014_02189244; size: 0x90.
int func_ov014_02189244(Table* p,Table* raw,unsigned char* already,void (*callback)(Table*,unsigned*)){*already=0;if(!raw)return 0;memcpy(p,raw,12);p->base=(unsigned*)((unsigned char*)raw+12);p->relocBase=(unsigned char*)raw+(func_ov014_0218934c(p)+12);if(p->flags>>31){*already=1;return 1;}func_ov014_021891f0(p,callback);p->flags=(p->flags&~0x80000000)|0x80000000;raw->flags=(raw->flags&~0x80000000)|0x80000000;return 1;}
}
