#include <globaldefs.h>
ARM
struct State; struct Tree; struct Table; struct List;
extern "C" {
Tree* Menu_FindSessionArenaById(Tree*,unsigned);
char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
void Menu_CountCompletedCatalogueMatches(void*,unsigned,int,signed char,short*,short*);
void Menu_StoreCategoryCompletionCounts(void*,unsigned,unsigned short,unsigned short,unsigned char,unsigned char);
void* Menu_GetDisplayRecordRegistry(State*);
void* MenuRecordList_LocateByKey(void**,unsigned short);
void Menu_ClearCatalogueSelection(Table*);
void World_LinkKeyedRecordsAndSetEnabledFlags(List*,void*);
}
struct Entry {short kind, mode; unsigned char enabled,total;};
struct Counts { Entry entries[20]; unsigned short enabled,total; unsigned char state; };
// Original data: arm9/ov004 @ 0x21707c0; symbol: data_ov004_021707c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" Counts* SumSixIndexedEntryByteValues_UnknownRoleZeroInitializedStorage;
struct RecordView { virtual void Reserved00(); virtual void Reserved01(); virtual void Reserved02(); virtual void Reserved03(); virtual void Reserved04(); virtual void Reserved05(); virtual void Reserved06(); virtual void Reserved07(); virtual void Reserved08(); virtual void Reserved09(); virtual void Reserved10(); virtual void Reserved11(); virtual void Reserved12(); virtual void Reserved13(); virtual void Reserved14(); virtual void Reserved15(); virtual void Reserved16(); virtual void Reserved17(); virtual void Reserved18(); virtual void Reserved19(); virtual void Reserved20(); virtual void Reserved21(); virtual void Reserved22(); virtual void Reserved23(); virtual void Reserved24(); virtual void Reserved25(); virtual void Reserved26(); virtual void Reserved27(); virtual void Reserved28(); virtual void Reserved29(); virtual void Reserved30(); virtual void Reserved31(); virtual void Reserved32(); virtual void Reserved33(); virtual void Reserved34(); virtual void Reserved35(); virtual void Reserved36(); virtual void Reserved37(); virtual void Reserved38(); virtual void Reserved39(); virtual void Reserved40(); virtual void Reserved41(); virtual void Reserved42(); virtual void Reserved43(); virtual void Reserved44(); virtual void Reserved45(); virtual void Reserved46(); virtual void Reserved47(); virtual void Reserved48(); virtual void Reserved49(); virtual void Reserved50(); virtual void Reserved51(); virtual void Reserved52(); virtual void Reserved53(); virtual void Reserved54(); virtual void Reserved55(); virtual void Reserved56(); virtual void Reserved57(); virtual void* GetRecords(); virtual Table* GetTable(); };
// Original: arm9/ov004 @ 0x02154350; symbol: func_ov004_02154350; size: 0x2A0.
// Builds twenty six-byte per-category counters and links record tables to the selected list.
extern "C" int AllocateAndPopulateCategoryBitCounts(State* self){
 void* node=Menu_FindSessionArenaById((Tree*)self,0);
 if(!node) return 0;
 Counts* counts=(Counts*)_ZN13SafeAllocator8AllocateEj((unsigned)((char*)node+4),126);
 SumSixIndexedEntryByteValues_UnknownRoleZeroInitializedStorage=counts;
 if(!counts) return 0;
 for(unsigned char i=0;i<20;i++){
  counts->entries[i].kind=-1; counts->entries[i].mode=-1;
  counts->entries[i].enabled=0; counts->entries[i].total=0;
 }
 counts->enabled=0; counts->total=0; counts->state=0;
 unsigned char index=0;
 short enabled=0,total=0;
 for(signed char mode=0;mode<=11;mode++){
  Menu_CountCompletedCatalogueMatches(self,-1,0,mode,&enabled,&total);
  ((void(*)(void*,unsigned,int,int,unsigned char,unsigned char))Menu_StoreCategoryCompletionCounts)(SumSixIndexedEntryByteValues_UnknownRoleZeroInitializedStorage,index,0,mode,(unsigned char)total,(unsigned char)enabled);
  index++;
 }
 for(signed char kind=1;kind<=6;){
  Menu_CountCompletedCatalogueMatches(self,-1,kind,-1,&enabled,&total);
  ((void(*)(void*,unsigned,int,int,unsigned char,unsigned char))Menu_StoreCategoryCompletionCounts)(SumSixIndexedEntryByteValues_UnknownRoleZeroInitializedStorage,index,kind,-1,(unsigned char)total,(unsigned char)enabled);
  kind++; index++;
 }
 Menu_CountCompletedCatalogueMatches(self,-1,7,-1,&enabled,&total);
 ((void(*)(void*,unsigned,int,int,unsigned char,unsigned char))Menu_StoreCategoryCompletionCounts)(SumSixIndexedEntryByteValues_UnknownRoleZeroInitializedStorage,index,7,-1,(unsigned char)total,(unsigned char)enabled);
 Counts* result=SumSixIndexedEntryByteValues_UnknownRoleZeroInitializedStorage;
 for(unsigned char i=0;i<20;i++){
  Entry* entry=&result->entries[i];
  result->enabled+=entry->enabled;
  result->total+=entry->total;
 }
 RecordView* source=(RecordView*)MenuRecordList_LocateByKey((void**)Menu_GetDisplayRecordRegistry(self),45);
 RecordView* destination=(RecordView*)MenuRecordList_LocateByKey((void**)Menu_GetDisplayRecordRegistry(self),57);
 if(source && destination){
  Table* table=destination->GetTable();
  if(table){
   Menu_ClearCatalogueSelection(table);
   void* records=source->GetRecords();
   World_LinkKeyedRecordsAndSetEnabledFlags((List*)table,records);
  }
 }
 return 0;
}
