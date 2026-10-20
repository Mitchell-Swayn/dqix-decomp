#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
struct Vector3i { int x,y,z; Vector3i& operator=(const Vector3i&); }; struct Object3D { void SetScale(const Vector3i*); };
extern "C" {
struct Table {unsigned short first,count,n,m;unsigned flags;unsigned* base;unsigned char* relocBase;};
struct Stream { unsigned char data[0x14]; short index,active; int handle; void* source; };
struct Owner { unsigned char pad[0x3c]; SafeAllocator* allocators; Object3D* object; unsigned word;void* current;unsigned char pad2[0x20];int task,load,frame,otherTask;unsigned char f7c,f7d,count,active,selected,flags,f82,gap[3];short tasks[5];unsigned char gap2[0x14];unsigned char list[0x10];SafeAllocator* arrays;void* head;void* node;void* service;unsigned words[7];unsigned char nested[0x80];unsigned a,b,c;int handle;unsigned extra;short pane,index,extra2,page,last;unsigned char state,phase,other[2],options,closed;unsigned short field;short values[8]; };
// Original data: arm9/ov014 @ 0x21897c4; symbol: data_ov014_021897c4.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex cc971802dc971802.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov014.md.
extern const char* BestiaryHabitatAdvanceLoad_UnknownRoleDataReferences[2];void BestiaryHabitat_CopyTableForMonster(Stream*,void*,void*,unsigned,int);int BestiaryHabitat_CancelLoad(Stream*);
// Original: arm9/ov014 @ 0x02188C34; symbol: func_ov014_02188c34; size: 0xDC.
int BestiaryHabitat_AdvanceLoad(Stream* p){BackgroundLoader* loader=BackgroundLoader::GetInstance();switch(p->active){case 1:p->handle=loader->QueueLoadFileInGP2(BestiaryHabitatAdvanceLoad_UnknownRoleDataReferences[1],BestiaryHabitatAdvanceLoad_UnknownRoleDataReferences[0],0);p->active=2;return BestiaryHabitat_AdvanceLoad(p);case 2:if(!loader->GetTaskStatus(p->handle))return 0;p->active=3;return BestiaryHabitat_AdvanceLoad(p);case 3:{void* data=0;unsigned length=0;loader->GetLoadedFileByID(p->handle,&data,&length);BestiaryHabitat_CopyTableForMonster(p,p->source,data,length,p->index);BestiaryHabitat_CancelLoad(p);return 1;}default:return 1;}}
}
