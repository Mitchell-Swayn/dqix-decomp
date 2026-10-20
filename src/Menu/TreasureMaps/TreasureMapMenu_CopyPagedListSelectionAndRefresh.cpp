#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
// Original data: arm9/ov004 @ 0x2171010; symbol: data_ov004_02171010.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" char* PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameResources_GetInstance();
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" char* MenuRecordList_LocateByKey(void*,int);
extern "C" int MenuRecord_GetType(void*);
extern "C" int GameResources_IsSelectedScreenBrightnessNeutral(void*,int);
extern "C" void Menu_GetGridPageAndPageCount(void*,short*,short*);
extern "C" void TreasureMapMenu_PopulateVisibleMapPage(void*);
// Original: arm9/ov004 @ 0x021654A8; symbol: CopyTypeSevenOffsetPairAndRefreshOwner; size: 0xc4.
extern "C" int TreasureMapMenu_CopyPagedListSelectionAndRefresh(void* self) {
 _ZN9GameState11GetInstanceEv();void* resources=GameResources_GetInstance();char* record=MenuRecordList_LocateByKey(Menu_GetDisplayRecordRegistry(self),10);if(!record)return 0;if(MenuRecord_GetType(record)!=7)return 0;
 if(B(PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage,0x18f4)<=8 || !GameResources_IsSelectedScreenBrightnessNeutral(resources,0)){short y=H(PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage,0x18f8);short x=H(PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage,0x18f6);H(record,0x5c)=x;H(record,0x5e)=y;return 0;}
 Menu_GetGridPageAndPageCount(record,(short*)(PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage+0x18f6),(short*)(PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage+0x18f8));TreasureMapMenu_PopulateVisibleMapPage(self);return 0;
}
