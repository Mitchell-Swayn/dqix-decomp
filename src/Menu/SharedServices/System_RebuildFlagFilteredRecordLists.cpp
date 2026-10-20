#include <globaldefs.h>
ARM
#pragma always_inline on
#include <Memory/SafeAllocator.h>
struct S;
extern "C" void* memset(void*,int,unsigned);
extern "C" int sprintf(char*,const char*,...);
extern "C" void* GameState_GetSerializedProgressState();
extern "C" int Script_GetPackedEntryState(volatile unsigned char*,int);
extern "C" unsigned Script_GetEntryHighFlagMask(unsigned char*,int);
extern "C" void* Quest_GetGlobalOrderState();
extern "C" unsigned Quest_TestCompletionFlag(unsigned char*,int);
extern "C" unsigned Quest_GetIdByOrderIndex(S*,unsigned);
extern "C" void QuestMenu_ClearEntryLinksAndActiveList();
struct Key { unsigned short id:9,flag9:1,flag10:1,flag11:1,flag12:1,pad:3; };
struct Item { short index; volatile unsigned short status:2,flag2:1,flag3:1,flag4:1,flag5:1,pad:10; char name[4]; unsigned value; };
struct Lists { Item* first; Item* second; char pad[0x28]; SafeAllocator allocator; char pad44[4]; short countA,countB; char pad4c[2]; short count; };
// Original data: arm9/ov004 @ 0x217101c; symbol: data_ov004_0217101c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" Lists* FilesystemQueuePositionRecord_UnknownRoleZeroInitializedStorage;
extern "C" char System_RebuildFlagFilteredRecordLists_Format03D[];
inline void ClearItem(Item* p) { p->index=-1;p->status=0;p->flag2=0;p->flag3=0;p->flag4=0;p->flag5=0;p->value=0;memset(p->name,0,4); }
// Original: arm9/ov004 @ 0x02166198; symbol: func_ov004_02166198; size: 0x470.
extern "C" void System_RebuildFlagFilteredRecordLists() {
Lists* lists=FilesystemQueuePositionRecord_UnknownRoleZeroInitializedStorage;
short max=lists->count;
unsigned char* owner=(unsigned char*)Quest_GetGlobalOrderState();
Item* first;
Item* second;
Key* table=*(Key**)(owner+0xa8);
unsigned char* global=(unsigned char*)GameState_GetSerializedProgressState();
short countA=0,countB=0;
{
Key* key;
for(short i=1;i<=max;i++) {
unsigned id=Quest_GetIdByOrderIndex((S*)owner,(unsigned char)i);
key=table;
int j;
for(j=0;j<204;j++,key++) if(key->id==id) break;
if(j==204) continue;
if(key->id && key->id<255) {
int status=Script_GetPackedEntryState(global,key->id);
if(key->flag10) {if(Script_GetEntryHighFlagMask(global,key->id)) countB++;}
else switch(status) {
case 1: if(Quest_TestCompletionFlag(owner,key->id)) countA++;break;
case 2:case 3:countA++;break;
case 0: if(Quest_TestCompletionFlag(owner,key->id)) countA++;break;

}
}
}
}
lists->countA=countA;lists->countB=countB;
lists->first=0;lists->second=0;
lists->allocator.Reset();
if(countA) lists->first=(Item*)lists->allocator.Allocate(countA*sizeof(Item));
if(countB) lists->second=(Item*)lists->allocator.Allocate(countB*sizeof(Item));
short indexA=0,indexB=0;
first=lists->first;
second=lists->second;
{
short i;
int status;
Key* key;
for(i=1;i<=max;i++) {
unsigned id=Quest_GetIdByOrderIndex((S*)owner,(unsigned char)i);
key=table;
int j;
for(j=0;j<204;j++,key++) if(key->id==id) break;
if(j==204) continue;
if(key->id && key->id<255) {
status=Script_GetPackedEntryState(global,key->id);
bool enabled=false;
if(key->flag10) {
if(Script_GetEntryHighFlagMask(global,key->id)) {
enabled=true;
if(status==1 && Quest_TestCompletionFlag(owner,key->id)) status=3;
}
} else switch(status) {
case 1: if(Quest_TestCompletionFlag(owner,key->id)) {enabled=true;status=3;}break;
case 2:case 3:enabled=true;break;
case 0: if(Quest_TestCompletionFlag(owner,key->id)) {enabled=true;status=3;}break;

}
if(enabled) {
short* index=&indexA;
Item* item=first+indexA;
if(key->flag10) {item=second+indexB;index=&indexB;}
ClearItem(item);
item->index=i;
item->status=(unsigned short)status;
item->flag2=key->flag10;
item->flag3=key->flag12;
item->flag4=key->flag9;
item->flag5=key->flag11;
sprintf(item->name,System_RebuildFlagFilteredRecordLists_Format03D,i);
item->value=0;
(*index)++;
}
}
}
}
QuestMenu_ClearEntryLinksAndActiveList();
}
