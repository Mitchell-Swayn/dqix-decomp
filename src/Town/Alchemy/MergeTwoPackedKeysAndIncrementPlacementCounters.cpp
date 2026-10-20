#include <globaldefs.h>
ARM
typedef short s16;
struct Table;struct Object;struct Entry;struct Counters;
struct CounterBuffer {unsigned char pad[0x68];unsigned counter;unsigned char tail[0x44];};
struct Record {short key;unsigned short first:1,second:1,rest:14;};
extern "C" {
void _ZN16BackgroundLoader21FreeAllocationsGlobalEv();
void _ZN16BackgroundLoader13AddLockGlobalEv();
void _ZN16BackgroundLoader16RemoveLockGlobalEv();
unsigned char* ScriptRecordTable_FindById(unsigned char*,int);
void Statistics_AddCompactAlchemyCount(Counters*,unsigned);
int GameState_StoreAlchemyOperationCount(const void*);
int GameState_CopyAlchemyOperationCount(void*);
int MergeEntriesIntoGameStateCollection(void*,Entry*,int);
int GameState_ReadIdAndFlagsFromPackedRecordList(void*,short*,Record*,int);
int GameState_StoreStatisticsRecord(const void*);
bool GameState_CopyStatisticsRecord(void*);
void InitializeInvalidPackedKeyRecord(Record*);
void Util_UpdateOrInsertHalfwordRecord(Table*,const Record*);
short GameState_CountAndStoreFlaggedEntries(Object*);
// Original data: arm9/main @ 0x211e33c; symbol: data_0211e33c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 7889 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char Main_UnknownRoleZeroInitializedStorage_Variant6[];
}
// Original: arm9/ov006 @ 0x02153CBC; symbol: func_ov006_02153cbc; size: 0x198.
// Merges two packed keys, marks corresponding list entries, and increments saturated counters.
extern "C" void MergeTwoPackedKeysAndIncrementPlacementCounters(Table* self,short first,short second,unsigned char* list) {
 _ZN16BackgroundLoader13AddLockGlobalEv();_ZN16BackgroundLoader21FreeAllocationsGlobalEv();
 CounterBuffer buffer;Record record;unsigned count;
 InitializeInvalidPackedKeyRecord(&record);
 if(GameState_ReadIdAndFlagsFromPackedRecordList(0,(short*)&first,&record,1)) {
  record.first=1;record.second=1;
  MergeEntriesIntoGameStateCollection(Main_UnknownRoleZeroInitializedStorage_Variant6,(Entry*)&record,1);
  Util_UpdateOrInsertHalfwordRecord(self,&record);
  if(list) {unsigned char* found=ScriptRecordTable_FindById(list,(short)first);if(found) *(unsigned*)(found+0x10)|=0x400000;}
 }
 if((short)second>0) {
  InitializeInvalidPackedKeyRecord(&record);
  if(GameState_ReadIdAndFlagsFromPackedRecordList(0,(short*)&second,&record,1)) {
   record.key=(short)second;record.second=1;
   MergeEntriesIntoGameStateCollection(Main_UnknownRoleZeroInitializedStorage_Variant6,(Entry*)&record,1);
   Util_UpdateOrInsertHalfwordRecord(self,&record);
   if(list) {unsigned char* found=ScriptRecordTable_FindById(list,(short)second);if(found) *(unsigned*)(found+0x10)|=0x400000;}
   GameState_CountAndStoreFlaggedEntries((Object*)self);
  }
 }
 count=0;
 if(GameState_CopyAlchemyOperationCount(&count)) {
  ++count;if(count>99999) count=99999;
  GameState_StoreAlchemyOperationCount(&count);
  GameState_CopyStatisticsRecord(&buffer);
  Statistics_AddCompactAlchemyCount((Counters*)(&buffer.counter),1);
  GameState_StoreStatisticsRecord(&buffer);
 }
 _ZN16BackgroundLoader16RemoveLockGlobalEv();
}
