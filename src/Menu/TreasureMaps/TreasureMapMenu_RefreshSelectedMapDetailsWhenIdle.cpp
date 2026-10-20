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
extern "C" void* GameState_ReadPResources(void*);
extern "C" int _Z28IsBrightnessTransitionActiveP13GameResources(void*);
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* MenuRecordList_LocateByKey(void*,int);
extern "C" int MenuRecord_GetType(void*);
extern "C" int Menu_GetSelectedGridRow(void*);
extern "C" void PopulateSelectedRecordTextPanel(void*,void*);
// Original: arm9/ov004 @ 0x0216556C; symbol: RefreshSelectedTypeSevenRecordAfterBrightnessTransition; size: 0xc4.
extern "C" int TreasureMapMenu_RefreshSelectedMapDetailsWhenIdle(void* self) {
 if(!B(PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage,0x18f4))return 0;if(_Z28IsBrightnessTransitionActiveP13GameResources(GameState_ReadPResources(_ZN9GameState11GetInstanceEv())))return 0;
 char* state=PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage;char* flag=state+0x18fd;unsigned active=B(state,0x18fd);if(active){*flag=0;return 0;}
 void* record=MenuRecordList_LocateByKey(Menu_GetDisplayRecordRegistry(self),10);if(!record)return 0;if(MenuRecord_GetType(record)!=7)return 0;int id=Menu_GetSelectedGridRow(record);PopulateSelectedRecordTextPanel(self,PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage+0xb01+id*452);return 0;
}
