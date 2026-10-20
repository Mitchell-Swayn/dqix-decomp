#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
extern "C" void* memset(void*,int,unsigned);
extern "C" void* memcpy(void*,const void*,unsigned);
struct Table {unsigned short count,other;unsigned size:31;unsigned relocated:1;char* records;char* payload;};
struct Record {char before[12];unsigned char count;char rest[31];unsigned* values;};
struct Cursor {unsigned* entries;int index;};
struct Owner {unsigned short valid;char pad[6];Record* record;char rest[4];};
extern "C" unsigned BestiaryInfo_ComputeTableDataSize(Table*);
extern "C" void BestiaryInfo_ForEachRecord(Table*,int);
extern "C" int BestiaryInfo_GetMonsterId(const void*);
extern "C" Record* BestiaryInfo_FindEntryByKey(Table*,int,int (*)(const void*));
extern "C" char* BestiaryInfo_ResolveStringOffset(Table*,unsigned,int);
extern "C" char* Allocator_DuplicateTerminatedString(SafeAllocator*,char*);
// Original: arm9/main @ 0x02097054; symbol: func_02097054; size: 0x154.
extern "C" ARM void BestiaryInfo_LoadSelectedMonsterRecord(Owner* owner,SafeAllocator* heap,void* file,void* unused,short key){memset(owner,0,16);Table table;if(key<0)return;if(file){memcpy(&table,file,8);table.records=(char*)file+8;table.payload=(char*)file+(BestiaryInfo_ComputeTableDataSize(&table)+8);if(!table.relocated){BestiaryInfo_ForEachRecord(&table,0);table.relocated=1;((Table*)file)->relocated=1;}}Record* copy;Record* original=BestiaryInfo_FindEntryByKey(&table,key,BestiaryInfo_GetMonsterId);copy=(Record*)heap->Allocate(48);if(original&&copy){memcpy(copy,original,48);Cursor cursor;unsigned char count=copy->count;void* allocated=heap->Allocate(count*4);cursor.entries=(unsigned*)(table.records+table.count*48)+(unsigned)original->values;original=(Record*)allocated;copy->values=(unsigned*)original;for(cursor.index=0;cursor.index<(int)count;++cursor.index){char* text=BestiaryInfo_ResolveStringOffset(&table,*cursor.entries++,0);*(char**)original=Allocator_DuplicateTerminatedString(heap,text);original=(Record*)((char*)original+4);}owner->valid=1;owner->record=copy;}}
