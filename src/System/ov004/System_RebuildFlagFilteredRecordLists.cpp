#include <globaldefs.h>
ARM
#pragma always_inline on
#include <Memory/SafeAllocator.h>
struct S;
extern "C" void* memset(void*,int,unsigned);
extern "C" int sprintf(char*,const char*,...);
extern "C" void* ReadGlobalValueAt02108844();
extern "C" int ReadOneOf204PackedTwoBitValues(volatile unsigned char*,int);
extern "C" unsigned TestOneOf204PackedNibbleHighFlags(unsigned char*,int);
extern "C" void* Object_GetGlobalRequestQueue();
extern "C" unsigned TestOwnerPackedBitInEmbeddedBuffer(unsigned char*,int);
extern "C" unsigned ReadValueBelow204OrFF(S*,unsigned);
extern "C" void Object_ClearTwoEntryArrayValuesAndCounts();
struct Key { unsigned short id:9,flag9:1,flag10:1,flag11:1,flag12:1,pad:3; };
struct Item { short index; volatile unsigned short status:2,flag2:1,flag3:1,flag4:1,flag5:1,pad:10; char name[4]; unsigned value; };
struct Lists { Item* first; Item* second; char pad[0x28]; SafeAllocator allocator; char pad44[4]; short countA,countB; char pad4c[2]; short count; };
extern "C" Lists* data_ov004_0217101c;
extern "C" char data_ov004_021705a0[];
inline void ClearItem(Item* p) { p->index=-1;p->status=0;p->flag2=0;p->flag3=0;p->flag4=0;p->flag5=0;p->value=0;memset(p->name,0,4); }
// Original: arm9/ov004 @ 0x02166198; symbol: func_ov004_02166198; size: 0x470.
extern "C" void System_RebuildFlagFilteredRecordLists() {
Lists* lists=data_ov004_0217101c;
short max=lists->count;
unsigned char* owner=(unsigned char*)Object_GetGlobalRequestQueue();
Item* first;
Item* second;
Key* table=*(Key**)(owner+0xa8);
unsigned char* global=(unsigned char*)ReadGlobalValueAt02108844();
short countA=0,countB=0;
{
Key* key;
for(short i=1;i<=max;i++) {
unsigned id=ReadValueBelow204OrFF((S*)owner,(unsigned char)i);
key=table;
int j;
for(j=0;j<204;j++,key++) if(key->id==id) break;
if(j==204) continue;
if(key->id && key->id<255) {
int status=ReadOneOf204PackedTwoBitValues(global,key->id);
if(key->flag10) {if(TestOneOf204PackedNibbleHighFlags(global,key->id)) countB++;}
else switch(status) {
case 1: if(TestOwnerPackedBitInEmbeddedBuffer(owner,key->id)) countA++;break;
case 2:case 3:countA++;break;
case 0: if(TestOwnerPackedBitInEmbeddedBuffer(owner,key->id)) countA++;break;

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
unsigned id=ReadValueBelow204OrFF((S*)owner,(unsigned char)i);
key=table;
int j;
for(j=0;j<204;j++,key++) if(key->id==id) break;
if(j==204) continue;
if(key->id && key->id<255) {
status=ReadOneOf204PackedTwoBitValues(global,key->id);
bool enabled=false;
if(key->flag10) {
if(TestOneOf204PackedNibbleHighFlags(global,key->id)) {
enabled=true;
if(status==1 && TestOwnerPackedBitInEmbeddedBuffer(owner,key->id)) status=3;
}
} else switch(status) {
case 1: if(TestOwnerPackedBitInEmbeddedBuffer(owner,key->id)) {enabled=true;status=3;}break;
case 2:case 3:enabled=true;break;
case 0: if(TestOwnerPackedBitInEmbeddedBuffer(owner,key->id)) {enabled=true;status=3;}break;

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
sprintf(item->name,data_ov004_021705a0,i);
item->value=0;
(*index)++;
}
}
}
}
Object_ClearTwoEntryArrayValuesAndCounts();
}
