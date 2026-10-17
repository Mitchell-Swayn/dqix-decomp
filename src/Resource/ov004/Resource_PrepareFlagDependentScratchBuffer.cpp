#include <globaldefs.h>
ARM
extern "C" {
void* _ZN9GameState11GetInstanceEv();
char* ReadGlobalValueAt02108844();
unsigned ReadNonnegativeIndexedBit(void*,unsigned char*,int);
int GameState_ReadWordAtOffset5CBC(void*);
char* FindTreeNodeForwarder(void*,unsigned);
unsigned _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv(void*);
void* func_ov011_021849c8(void*);
char* func_ov023_021f6880(void*,unsigned);
unsigned OV023_ReadHalfwordField04(void*);
void* OV023_GetEmbeddedField20(void*);
void* ReadWordFieldAtOffset1C(void*);
char* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
void* Object_GetGlobalConnectionState();
bool TestActiveWordAndGlobalStateNonzero(void*);
void* memset(void*,int,unsigned);
void ClearOwnerBuffersAndResetSignedByteSentinels(void*);
void SetOneOfSixteenWordFieldsAtOffset8B0(void*,int,unsigned);
void* FindRecordValueByKeyOrZero(void*,int);
void ProcessSixStagesUsingSharedWordScratchBuffer(void*,int,void*,void*,int,int,unsigned);
void SetHalfwordPair10C(void*,unsigned short,unsigned short);
char* GameResources_GetInstance();
void WriteField9C4EnabledAnd9C8Value(void*,int,unsigned char);
void Object_SetBooleanByteAtOffset9C6(void*,int);
struct Table {int values[7];};extern Table data_ov004_02170138;
}
// Original: arm9/ov004 @ 0x0216AAEC; symbol: func_ov004_0216aaec; size: 0x1E4.
extern "C" int Resource_PrepareFlagDependentScratchBuffer(void* self){
void* gs=_ZN9GameState11GetInstanceEv();
char* global=ReadGlobalValueAt02108844();
Table table=data_ov004_02170138;
unsigned char count=0;
for(int i=0;i<7;i++)if(ReadNonnegativeIndexedBit(global,(unsigned char*)global+0x8c,table.values[i]))count++;
int key=GameState_ReadWordAtOffset5CBC(gs);
char* allocator=FindTreeNodeForwarder(self,4);if(!allocator)return 0;
_ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv(allocator+4);
char* item=func_ov023_021f6880(func_ov011_021849c8(self),0x192);if(!item)return 0;
if(OV023_ReadHalfwordField04(item)!=4)return 0;
void* record=OV023_GetEmbeddedField20(item);
void* owner=ReadWordFieldAtOffset1C(record);
char* scratch=_ZN13SafeAllocator8AllocateEj(allocator+4,4);
if(TestActiveWordAndGlobalStateNonzero(Object_GetGlobalConnectionState()))key=1000;
memset(scratch,0,0x960);
ClearOwnerBuffersAndResetSignedByteSentinels(owner);
SetOneOfSixteenWordFieldsAtOffset8B0(owner,0,count);
void* value=FindRecordValueByKeyOrZero(record,(short)key);
ProcessSixStagesUsingSharedWordScratchBuffer(owner,12,value,scratch,0xd7,0,1);
item=func_ov023_021f6880(func_ov011_021849c8(self),0x32);
if(item)*(void**)(item+0x20)=scratch;
item=func_ov023_021f6880(func_ov011_021849c8(self),0xc8);
if(item && OV023_ReadHalfwordField04(item)==6)SetHalfwordPair10C(item,0,4);
void* target=*(void**)(GameResources_GetInstance()+0x36d0);
WriteField9C4EnabledAnd9C8Value(target,1,0);
Object_SetBooleanByteAtOffset9C6(target,0);
return 0;
}
