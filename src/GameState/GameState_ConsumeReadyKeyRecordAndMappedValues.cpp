#include <globaldefs.h>
ARM
#pragma always_inline on
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetIndexList(void*);
extern "C" void* ReadGlobalValueAt02108844();
extern "C" int ReadOneOf204PackedTwoBitValues(volatile unsigned char*,int);
extern "C" void Object_SetBoundedIndexedModeFlag(void*,int);
extern "C" int CountedKeyRecords_RemoveById(void*,int);
extern "C" void SetMappedValueWithHighKeyOffsetAdjustment(char*,int,int);
extern "C" short SumIndexedValuesAcrossPresentPartyIds(void*,int);
extern "C" int GameState_TestKeyInContainersOrListedPartyMembers(unsigned char*,int);
struct Header {unsigned short key:9,pad:1,enabled:1,mappedCount:5;};
struct Record {Header header;unsigned short mapped[13];unsigned short count;short keys[5];Record* next;};
inline bool IsReady(char* flags,int key){return ReadOneOf204PackedTwoBitValues((volatile unsigned char*)flags,key)==2;}
// Original: arm9/main @ 0x02095D30; symbol: func_02095d30; size: 0x160.
extern "C" int GameState_ConsumeReadyKeyRecordAndMappedValues(char* p,int key,int clearMapped) {
 if(!*(Record**)(p+0xa4))return 0;
 void* state=_ZN9GameState11GetInstanceEv();
 char* flags=(char*)ReadGlobalValueAt02108844();
 unsigned char* list=(unsigned char*)GameState_GetIndexList(state);
 Record* record=*(Record**)(p+0xa4);
 for(;record;record=record->next) {
  if(key==record->header.key && IsReady(flags,key)) {
   if(!record->header.enabled)return 0;
   Object_SetBoundedIndexedModeFlag(flags,key);
   CountedKeyRecords_RemoveById(p,key);
   if(clearMapped)for(int i=0;i<(int)record->header.mappedCount;i++)SetMappedValueWithHighKeyOffsetAdjustment(flags,record->mapped[i],0);
   for(int i=0;i<record->count;i++) {
    int value=record->keys[i];
    if(value>0) {
     int count=SumIndexedValuesAcrossPresentPartyIds(list,value);
     for(int j=0;j<count;j++)GameState_TestKeyInContainersOrListedPartyMembers(list,record->keys[i]);
    }
   }
   break;
  }
 }
 if(!record)return 0;return 1;
}
