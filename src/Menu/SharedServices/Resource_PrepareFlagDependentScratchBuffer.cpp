#include <globaldefs.h>
ARM
extern "C" {
void* _ZN9GameState11GetInstanceEv();
char* GameState_GetSerializedProgressState();
unsigned BitArray_ReadNonnegativeIndexMask(void*,unsigned char*,int);
int GameState_GetProgressMessageId(void*);
char* Menu_FindSessionArenaById(void*,unsigned);
unsigned _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv(void*);
void* Menu_GetDisplayRecordRegistry(void*);
char* MenuRecordList_LocateByKey(void*,unsigned);
unsigned MenuRecord_GetType(void*);
void* Menu_GetRecordMessageTable(void*);
void* TextContext_GetSharedInstance(void*);
char* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
void* Network_GetConnectionManager();
bool Network_IsClientSession(void*);
void* memset(void*,int,unsigned);
void TextLayout_ResetFormattingWorkspace(void*);
void TextContext_SetNumericArgument(void*,int,unsigned);
void* MessageTextTable_FindTextById(void*,int);
void TextMarkup_ExpandAndWrapText(void*,int,void*,void*,int,int,unsigned);
void MenuTextCanvas_SetLabelPalettePair(void*,unsigned short,unsigned short);
char* GameResources_GetInstance();
void WorldMap_RequestFadeInAfterDelay(void*,int,unsigned char);
void WorldMap_SetFadeInBlocked(void*,int);
// Original data: arm9/ov004 @ 0x2170138; symbol: data_ov004_02170138.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0400000005000000060000000700000008000000090000000a000000.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
struct Table {int values[7];};extern Table ResourcePrepareFlagDependentScratchBuffer_UnknownRoleInitializedBytes;
}
// Original: arm9/ov004 @ 0x0216AAEC; symbol: func_ov004_0216aaec; size: 0x1E4.
extern "C" int Resource_PrepareFlagDependentScratchBuffer(void* self){
void* gs=_ZN9GameState11GetInstanceEv();
char* global=GameState_GetSerializedProgressState();
Table table=ResourcePrepareFlagDependentScratchBuffer_UnknownRoleInitializedBytes;
unsigned char count=0;
for(int i=0;i<7;i++)if(BitArray_ReadNonnegativeIndexMask(global,(unsigned char*)global+0x8c,table.values[i]))count++;
int key=GameState_GetProgressMessageId(gs);
char* allocator=Menu_FindSessionArenaById(self,4);if(!allocator)return 0;
_ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv(allocator+4);
char* item=MenuRecordList_LocateByKey(Menu_GetDisplayRecordRegistry(self),0x192);if(!item)return 0;
if(MenuRecord_GetType(item)!=4)return 0;
void* record=Menu_GetRecordMessageTable(item);
void* owner=TextContext_GetSharedInstance(record);
char* scratch=_ZN13SafeAllocator8AllocateEj(allocator+4,4);
if(Network_IsClientSession(Network_GetConnectionManager()))key=1000;
memset(scratch,0,0x960);
TextLayout_ResetFormattingWorkspace(owner);
TextContext_SetNumericArgument(owner,0,count);
void* value=MessageTextTable_FindTextById(record,(short)key);
TextMarkup_ExpandAndWrapText(owner,12,value,scratch,0xd7,0,1);
item=MenuRecordList_LocateByKey(Menu_GetDisplayRecordRegistry(self),0x32);
if(item)*(void**)(item+0x20)=scratch;
item=MenuRecordList_LocateByKey(Menu_GetDisplayRecordRegistry(self),0xc8);
if(item && MenuRecord_GetType(item)==6)MenuTextCanvas_SetLabelPalettePair(item,0,4);
void* target=*(void**)(GameResources_GetInstance()+0x36d0);
WorldMap_RequestFadeInAfterDelay(target,1,0);
WorldMap_SetFadeInBlocked(target,0);
return 0;
}
