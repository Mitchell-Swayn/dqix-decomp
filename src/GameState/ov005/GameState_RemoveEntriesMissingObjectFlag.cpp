#include <globaldefs.h>
ARM
struct Kind {unsigned value:4,rest:28;};
struct Payload {unsigned first;unsigned pad:27,flag0:1,flag1:1,rest:3;};
struct Entry {Payload* payload;char* text;Kind kind;};
struct Bit {unsigned char value:1,rest:7;};
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* GameState_GetObjectWithFlag100(void*,int);
extern "C" char* GameState_GetIndexList(void*);
extern "C" int ReadLinkedHalfwordArrayElementOrMinusOne(char*,int);
extern "C" Entry* FindSerializedPrimaryRecordByKey(void*,int);
extern "C" void WriteChangedStatAndMarkDirty(void*,int,int);
extern "C" unsigned char* ReadWordFieldAtOffset150(void*);
extern "C" void Graphics_CopyTypedRecordIntoSlot(void*,Entry*,int);
extern "C" void Object_ClearKindMappedDataTextSlot(unsigned char*,int);
extern "C" int AddPositiveItemQuantityWithinTypeGroup(void*,unsigned,int,unsigned);
extern "C" unsigned char data_ov005_0215cc0c[];
// Original: arm9/ov005 @ 0x0215840C; symbol: func_ov005_0215840c; size: 0x154.
extern "C" int GameState_RemoveEntriesMissingObjectFlag(char* self,int index) {
 void* game=_ZN9GameState11GetInstanceEv();
 char* object=GameState_GetObjectWithFlag100(game,index);
 if(!object)return 0;
 int result=0;
 int selected=((Bit*)(*(char**)(object+0x150)+0x49c))->value;
 for(int i=0;i<7;i++) {
 Entry* entry; int slot=data_ov005_0215cc0c[i];
 int key=ReadLinkedHalfwordArrayElementOrMinusOne(object,slot);
 entry=FindSerializedPrimaryRecordByKey(*(void**)(self+0xdf4),key);
 if(!entry)continue;
 int flags[2]={entry->payload->flag0,entry->payload->flag1};
 if(flags[selected])continue;
 int fallback=-1;int custom=-1;
 if(slot==0) {fallback=1000;custom=0;}
 WriteChangedStatAndMarkDirty(object,slot,-1);
 unsigned char* target=ReadWordFieldAtOffset150(object);
 Entry* replacement=FindSerializedPrimaryRecordByKey(*(void**)(self+0xdf4),fallback);
 if(replacement)Graphics_CopyTypedRecordIntoSlot(target,replacement,custom);
 else Object_ClearKindMappedDataTextSlot(target,entry->kind.value);
 AddPositiveItemQuantityWithinTypeGroup(GameState_GetIndexList(game)+0x1d4,key,1,entry->kind.value);
 result=1;
 }
 return result;
}
