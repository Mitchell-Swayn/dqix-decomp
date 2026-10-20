#include <globaldefs.h>
ARM
extern "C" int Menu_GetSelectedGridIndex(...);
extern "C" int MenuRecord_GetType(...);
extern "C" int ScriptEntryTable_FindByPrimaryKey(...);
extern "C" int Menu_QueueScriptEntry(...);
extern "C" int Menu_GetDisplayRecordRegistry(...);
extern "C" int MenuRecordList_LocateByKey(...);
extern "C" void* memset(void*,int,unsigned);extern "C" void* memcpy(void*,const void*,unsigned);
// Original data: arm9/ov004 @ 0x21707c8; symbol: data_ov004_021707c8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" char MenuPopulateCollectionTextPage_UnknownRoleZeroInitializedStorage[];
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov004 @ 0x021560E8; symbol: SelectStateFromIndexedTableTopTwoBits; size: 0xc8.
extern "C" int Menu_EnterSelectedCollectionCategory(void* self){
char* entry=C(MenuRecordList_LocateByKey(Menu_GetDisplayRecordRegistry(self),3));if(!entry)return 0;if(MenuRecord_GetType(entry)!=7)return 0;short row=(short)(S(entry,0x5c)*12);int index=Menu_GetSelectedGridIndex(entry)+row;char* selected=C(ScriptEntryTable_FindByPrimaryKey(P(MenuPopulateCollectionTextPage_UnknownRoleZeroInitializedStorage,12),S(P(MenuPopulateCollectionTextPage_UnknownRoleZeroInitializedStorage,8),index*2)));if(!selected)return 0;unsigned kind=(unsigned)W(selected,0)>>30;switch(kind){case 0:Menu_QueueScriptEntry(self,110);break;case 1:Menu_QueueScriptEntry(self,111);break;case 2:Menu_QueueScriptEntry(self,112);break;}return 0;
}
