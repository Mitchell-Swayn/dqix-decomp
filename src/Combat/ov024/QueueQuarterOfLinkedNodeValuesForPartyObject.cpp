#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* GameState_GetObjectWithFlag100(void*,int);
extern "C" int TestPositiveCountAndField2F4Bit3(char*);
extern "C" void SetBitInTwoWordMask(void*,void*,unsigned);
extern "C" short AddClampedLinkedHalfwordValue(void*,int,int,short*);
extern "C" void Object_AddIndexedEntryAndLink(void*,void*,int);
struct Mask;
extern "C" void PopulateRecordFromDescriptorFields(void*,void*,void*,short,short,short,Mask,unsigned char);
extern "C" void* ClearCurrentIndexedRecord(unsigned char*);
extern "C" void AppendLinkedEntryAndIncrementCount(char*,void*,int);
extern "C" char* ReadIndexedListNode(void*,int,int);
extern "C" char* GetSecondaryLinkedRecordByIndex(void*,int);
struct Mask { unsigned low,high; };
// Original: arm9/ov024 @ 0x021E6104; symbol: func_ov024_021e6104; size: 0x1C8.
extern "C" int QueueQuarterOfLinkedNodeValuesForPartyObject(char* self,int party,char* descriptor) {
 char* obj=GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),party);
 if(!obj) return 0;
 if((*(unsigned*)(descriptor+0x10)&0x400000) && (party>=0 && party<=3?1:0) && TestPositiveCountAndField2F4Bit3(*(char**)(obj+0x150))) {
 int sum=0;
 for(int i=0;i<*(unsigned char*)(*(char**)(self+4)+9);i++) {
 char* record=GetSecondaryLinkedRecordByIndex(*(void**)(self+4),i);
 if(record) {
 for(int j=0;j<*(unsigned char*)(record+0x18);j++) {
 char* node=ReadIndexedListNode(record,j,0);
 if(node) sum+=*(short*)(node+0xc);
 }
 }
 }
 int amount=sum>>2;
 if(amount>0) {
 char* nested=*(char**)(obj+0x138);
 unsigned maximum=*(volatile unsigned short*)(nested+4);
 unsigned current=*(volatile unsigned short*)nested;
 if(current<maximum) {
 short applied=0;
 short value=AddClampedLinkedHalfwordValue(*(void**)(self+0x10),party,amount,&applied);
 void* entry=ClearCurrentIndexedRecord(*(unsigned char**)(self+0x10));
 if(!entry) return 0;
 Object_AddIndexedEntryAndLink(*(void**)(self+0x10),entry,0x215);
 Mask mask;mask.low=0;mask.high=0;
 SetBitInTwoWordMask(*(void**)(self+0x10),&mask,0x25);
 short detail=*(volatile short*)(*(char**)(obj+0x138)+2);
 PopulateRecordFromDescriptorFields(*(void**)(self+0x10),entry,obj,(short)-applied,value,detail,mask,0);
 AppendLinkedEntryAndIncrementCount(*(char**)(self+8),entry,3);
 ++*(unsigned char*)(*(char**)(self+0x10)+0x8e02);
 }
 }
 }
 return 0;
}
