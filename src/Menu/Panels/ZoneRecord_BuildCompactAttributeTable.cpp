#include <globaldefs.h>
#pragma always_inline on
#include <World/Zone3DEmbeddedState.h>
#include <std_library_functions.h>
ARM
#pragma opt_rebuildconditionals off
#pragma opt_rebuildlogicals off
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
struct CompactRecord {short key; unsigned short category:4,unused:12;unsigned a:7,b:4,c:12,d:1,e:2,f:1,g:1,h:1,rest:3;};
struct CompactOwner {CompactRecord* entries;unsigned short count,used;};
struct SecondaryAttributes {
 unsigned a:7,b:4,skip:18,d:1,e:2;
 unsigned c:12,skip2:15,f:1,g:1,h:1,skip3:2;
};
static inline unsigned StorageSize(ZoneState2754::Data* p){unsigned primary=p->primaryCount; unsigned secondary=p->secondary.count; bool extra=p->secondary.hasExtraBlock; unsigned size=extra?88:0;return size+secondary*32+primary*32;}
static inline bool VisitRecords(ZoneState2754::Data* p,bool(*callback)(ZoneState2754::Data*,void*)){
 int count;int i;char* record=p->records;
 if(!record||!(count=p->primaryCount)||!(unsigned)callback)return false;
 for(i=0;i<count;i++,record+=32)callback(p,record);
 return true;
}
static inline bool Attach(ZoneState2754::Data* p,void* file,bool* relocated,bool(*callback)(ZoneState2754::Data*,void*)){
 *relocated=false;if(!file)return false;
 memcpy(p,file,12);p->records=(char*)file+12;p->payload=(char*)file+(StorageSize(p)+12);
 if(p->relocated){*relocated=true;return true;}
 VisitRecords(p,callback);p->relocated=1;((ZoneState2754::Data*)file)->relocated=1;return true;
}
static inline int Accepted(ZoneSerializedRecord* p){return p->category.category<=7?1:0;}
// Original: arm9/ov023 @ 0x021DAD8C; symbol: func_ov023_021dad8c; size: 0x300.
// Relocates serialized zone records and compacts supported secondary attributes into eight-byte entries.
extern "C" void ZoneRecord_BuildCompactAttributeTable(CompactOwner* self,unsigned allocator,void* file,unsigned size){
 if(!allocator||!file||!size)return;
 self->count=0;self->used=0;
 ZoneState2754::Data data;memset(&data,0,sizeof(data));
 bool relocated;Attach(&data,file,&relocated,RelocateSerializedRecordPayload);
 if(!relocated)data.RelocateSecondaryRecordLinks();
 int count;
 {ZoneSerializedRecord* record;int i;i=0;count=data.primaryCount;record=(ZoneSerializedRecord*)data.records;
 for(;i<count;i++,record++)if(Accepted(record))self->count++;}
 CompactRecord* output=(CompactRecord*)_ZN13SafeAllocator8AllocateEj(allocator,self->count*8);
 self->entries=output;if(!output)return;
 ZoneSerializedRecord* record=(ZoneSerializedRecord*)data.records;
 for(int i=0;i<count;i++,record++){
 if(Accepted(record) && record->secondary.pointer){
 SecondaryAttributes* attributes=(SecondaryAttributes*)record->secondary.pointer;
 self->used++;output->key=record->key;output->category=(unsigned short)record->category.category;
 output->a=attributes->a;output->b=attributes->b;output->c=attributes->c;
 output->d=attributes->d;output->e=attributes->e;output->f=attributes->f;output->g=attributes->g;output->h=attributes->h;
 output++;
 }
 }
}
