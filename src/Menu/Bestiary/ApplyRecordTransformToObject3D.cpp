#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
struct Vector3i { int x,y,z; Vector3i& operator=(const Vector3i&); }; struct Object3D { void SetScale(const Vector3i*); };
extern "C" {
struct Table {unsigned short first,count,n,m;unsigned flags;unsigned* base;unsigned char* relocBase;};
struct Stream { unsigned char data[0x14]; short index,active; int handle; void* source; };
struct Owner { unsigned char pad[0x3c]; SafeAllocator* allocators; Object3D* object; unsigned word;void* current;unsigned char pad2[0x20];int task,load,frame,otherTask;unsigned char f7c,f7d,count,active,selected,flags,f82,gap[3];short tasks[5];unsigned char gap2[0x14];unsigned char list[0x10];SafeAllocator* arrays;void* head;void* node;void* service;unsigned words[7];unsigned char nested[0x80];unsigned a,b,c;int handle;unsigned extra;short pane,index,extra2,page,last;unsigned char state,phase,other[2],options,closed;unsigned short field;short values[8]; };
struct Record {unsigned char pad[0x10];float position[3];float angle;float scale[3];};Record* BestiaryInfo_FindMonsterRecord(void*,int);
// Original: arm9/ov014 @ 0x02184C08; symbol: func_ov014_02184c08; size: 0x100.
void ApplyRecordTransformToObject3D(Owner* p){if(!p->current)return;Record* r=BestiaryInfo_FindMonsterRecord((unsigned char*)p+12,*(short*)((unsigned char*)p->current+12));if(!r)return;Vector3i position,rotation,scale;position.x=(int)(4096.0f*r->position[0]);position.y=(int)(4096.0f*r->position[1]);position.z=(int)(4096.0f*r->position[2]);rotation.x=0;rotation.y=(int)(4096.0f*r->angle);rotation.z=0;scale.x=(int)(4096.0f*r->scale[0]);scale.y=(int)(4096.0f*r->scale[1]);scale.z=(int)(4096.0f*r->scale[2]);*(Vector3i*)((unsigned char*)p->object+0x44)=position;*(Vector3i*)((unsigned char*)p->object+0x50)=rotation;p->object->SetScale(&scale);}
}
