#include <globaldefs.h>
ARM
extern "C" int Menu_GetGridPageAndPageCount(...);
extern "C" int GameResources_GetInstance(...);
extern "C" int GameResources_IsSelectedScreenBrightnessNeutral(...);
extern "C" int MenuRecord_GetType(...);
extern "C" int _ZN9GameState11GetInstanceEv(...);
extern "C" int TreasureMapMenu_PopulateVisibleMapPage(...);
extern "C" int Menu_GetDisplayRecordRegistry(...);
extern "C" int MenuRecordList_LocateByKey(...);
extern "C" void* memset(void*,int,unsigned);extern "C" void* memcpy(void*,const void*,unsigned);
// Original data: arm9/ov004 @ 0x2171010; symbol: data_ov004_02171010.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" char PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage[];
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov004 @ 0x02164670; symbol: SynchronizeTypeSevenCoordinatePairWithStoredValues; size: 0xc8.
extern "C" int TreasureMapMenu_SynchronizePageSelection(void* self){
char* entry=C(MenuRecordList_LocateByKey(Menu_GetDisplayRecordRegistry(self),10));if(!entry)return 0;if(MenuRecord_GetType(entry)!=7)return 0;_ZN9GameState11GetInstanceEv();void* resources=(void*)GameResources_GetInstance();if(!B(P(PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage,0),0x18f4)||!GameResources_IsSelectedScreenBrightnessNeutral(resources,0)||B(P(PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage,0),0x18fd)){short y=S(P(PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage,0),0x18f8);short x=S(P(PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage,0),0x18f6);H(entry,0x5c)=x;H(entry,0x5e)=y;return 0;}char* global=P(PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage,0);Menu_GetGridPageAndPageCount(entry,global+0x18f6,global+0x18f8);TreasureMapMenu_PopulateVisibleMapPage(self);return 0;
}
