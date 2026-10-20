#include <globaldefs.h>
ARM
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define I(p,o) (*(int*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))

#define S(p,o) (*(signed char*)((char*)(p)+(o)))
// Original data: arm9/ov004 @ 0x217101c; symbol: data_ov004_0217101c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void* Zone3D_GetMainInstance();extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);extern "C" void _ZN13ZoneState2754C1Ev(void*);extern "C" void World_ResetZoneStateAndClearThreeWords(unsigned char*);extern "C" void World_ResetTemporaryZoneResourceState(void*);extern "C" int Inventory_AddGroupedItemQuantityAndCacheResult(char*,unsigned,unsigned,...);extern "C" unsigned TextContext_GetSharedInstance();extern "C" char* FilesystemQueuePositionRecord_UnknownRoleZeroInitializedStorage;extern "C" char* TileGrid_ResolveByKey(void*,unsigned);extern "C" void Math_StoreSignedQuotientAndRemainder(void*,int);extern "C" void MenuSelectionGrid_RefreshCursorAndSelectionCallback(void*,void*);extern "C" unsigned Menu_GetSelectedGridRow(void*);extern "C" unsigned Menu_GetSelectedGridColumn(void*);extern "C" unsigned Menu_ReadGridEntryOrZero(void*,unsigned,unsigned);extern "C" void** Menu_GetDisplayRecordRegistry(void*);extern "C" void* MenuRecordList_LocateByKey(void**,unsigned short);extern "C" unsigned MenuRecord_GetType(void*);extern "C" void* OV023_FindTypeSixFromTypeEight(unsigned,void*,void*);extern "C" void Resource_SelectMatchingTypeEightLinkedRecord(unsigned short*,void*,int);
// Original: arm9/ov004 @ 0x02166730; symbol: Resource_SelectIndexedRowAndRefreshTypeEightRecord; size: 0x114.
extern "C" void QuestMenu_SelectQuestRowAndRefreshHighlight(void* self,int key){char* node=P(FilesystemQueuePositionRecord_UnknownRoleZeroInitializedStorage,8);short index=0;while(node){if(H(node,0)==key)break;index++;node=P(node,8);}short row=index/8,column=index%8;char* object=TileGrid_ResolveByKey(self,91);if(object){short y=H(object,94);H(object,92)=row;H(object,94)=y;Math_StoreSignedQuotientAndRemainder(object,(unsigned short)column);MenuSelectionGrid_RefreshCursorAndSelectionCallback(object,self);}unsigned first=Menu_GetSelectedGridRow(object);unsigned second=Menu_GetSelectedGridColumn(object);unsigned handle=Menu_ReadGridEntryOrZero(object,first,second);void* found=((void*(*)(void**,unsigned))MenuRecordList_LocateByKey)(Menu_GetDisplayRecordRegistry(self),handle);if(!found)return;if(MenuRecord_GetType(found)!=8)return;void* related=OV023_FindTypeSixFromTypeEight((unsigned)object,self,found);if(!related)return;Resource_SelectMatchingTypeEightLinkedRecord((unsigned short*)related,self,0x8000);}
