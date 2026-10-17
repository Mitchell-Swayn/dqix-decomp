#include <globaldefs.h>
ARM
struct Primary { int pad[3]; unsigned int low:12; unsigned int bitIndex:11; unsigned int high:9; };
struct Entry { int a; Primary* record; short key; unsigned char pad[4]; unsigned char flags,pad2; };
struct List { int state; Entry* entries; short count; };
extern "C" void* ReadGlobalValueAt02108844();
extern "C" unsigned int ReadNonnegativeIndexedBit(void*,unsigned char*,int);
extern "C" int _ZN13ZoneState27544Data19GetRecordCountBoundEv(void*);
extern "C" Primary* FindSerializedPrimaryRecordByKey(void*,int);
// Original: arm9/ov023 @ 0x021E1474; symbol: func_ov023_021e1474; size: 0xA4.
extern "C" void World_LinkKeyedRecordsAndSetEnabledFlags(List* list,void* data) {
if(!data)return;
_ZN13ZoneState27544Data19GetRecordCountBoundEv(data);
Entry* entry;
Entry* entries=list->entries;
short count=list->count;
for(short i=0;i<count;++i){
entry=&entries[i];
entry->record=FindSerializedPrimaryRecordByKey(data,entry->key);
if(entry->record){
int bit=(unsigned short)entry->record->bitIndex;
if(bit>0){unsigned char* state=(unsigned char*)ReadGlobalValueAt02108844();if(ReadNonnegativeIndexedBit(state,state+0x8c,bit+0xc76))entry->flags|=2;}
}
}
list->state=0;
}
