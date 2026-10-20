#include <globaldefs.h>
ARM
struct A { unsigned w[5]; unsigned short a,b; short c; unsigned short d,e; };
struct Keys { short v[4]; };
struct Record { A base; char pad[0x74-sizeof(A)]; };
extern "C" {
void* _ZN16BackgroundLoader11GetInstanceEv();
unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,unsigned);
void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);
void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
void _ZN13SafeAllocator5ResetEv(void*);
unsigned char* ScriptRecordTable_FindById(unsigned char*,int);
void CharacterState_CopyEquipmentDescriptor(A*,A*);
void ZoneState2754_UpdateRecordsForKeysFromSerializedData(int,int,int,int,short);
void KrakPot_QueueResultAndIngredientSprites(unsigned char*,unsigned char*);
void KrakPot_InitializeAlchemyItemDescriptor(char*);
// Original data: arm9/ov006 @ 0x215ffda; symbol: data_ov006_0215ffda.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffffffffffffffff.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov006.md.
extern Keys CompleteLoadedRecordGroup_UnknownRoleInitializedBytes;
}
// Original: arm9/ov006 @ 0x0215A384; symbol: func_ov006_0215a384; size: 0x258.
// Completes a loaded four-record group, resolves inherited keys, and queues models.
extern "C" int CompleteLoadedRecordGroup(unsigned char* self,int resolve) {
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,*(unsigned*)(self+0x354))) {
  void* file; unsigned length;
  _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,*(int*)(self+0x354),&file,&length);
  if(file) {
   _ZN13SafeAllocator5ResetEv(*(unsigned char**)(self+12)+0xa0);
   Keys keys=CompleteLoadedRecordGroup_UnknownRoleInitializedBytes;
   A records[4];
   for(unsigned char i=0;i<4;++i) {
    KrakPot_InitializeAlchemyItemDescriptor((char*)&((Record*)(self+0x17c))[i]);
    CharacterState_CopyEquipmentDescriptor(&records[i],&((Record*)(self+0x17c))[i].base);
   }
   unsigned char* source=*(unsigned char**)(self+0x34);
   if(source) {
    if(resolve) source=ScriptRecordTable_FindById(self+0x14c,*(short*)(source+0x14));
    keys.v[0]=*(short*)(self+0x1ec)=*(short*)(source+2);
   }
   keys.v[1]=*(short*)(self+0x260)=*(short*)(self+0x378);
   keys.v[2]=*(short*)(self+0x2d4)=*(short*)(self+0x37a);
   keys.v[3]=*(short*)(self+0x348)=*(short*)(self+0x37c);
   if(*(unsigned char**)(self+0x34)) {
    if(keys.v[1]<0) keys.v[1]=*(short*)(self+0x260)=*(short*)(*(unsigned char**)(self+0x34)+4);
    if(keys.v[2]<0) keys.v[2]=*(short*)(self+0x2d4)=*(short*)(*(unsigned char**)(self+0x34)+6);
    if(keys.v[3]<0) keys.v[3]=*(short*)(self+0x348)=*(short*)(*(unsigned char**)(self+0x34)+8);
   }
   ZoneState2754_UpdateRecordsForKeysFromSerializedData((int)records,(int)file,length,(int)&keys,4);
   if(keys.v[1]==keys.v[2] && keys.v[2]>0) CharacterState_CopyEquipmentDescriptor(&records[2],&records[1]);
   if(keys.v[1]==keys.v[3] && keys.v[3]>0) CharacterState_CopyEquipmentDescriptor(&records[3],&records[1]);
   if(keys.v[2]==keys.v[3] && keys.v[3]>0) CharacterState_CopyEquipmentDescriptor(&records[3],&records[2]);
   for(unsigned char i=0;i<4;++i) CharacterState_CopyEquipmentDescriptor(&((Record*)(self+0x17c))[i].base,&records[i]);
   KrakPot_QueueResultAndIngredientSprites(*(unsigned char**)(self+0x10),self+0x17c);
  }
  _ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(self+0x354));
  *(int*)(self+0x354)=-1;
 }
 return *(int*)(self+0x354)==-1;
}
