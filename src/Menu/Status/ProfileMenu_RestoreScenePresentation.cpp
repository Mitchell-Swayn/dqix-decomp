#include <globaldefs.h>
ARM
extern "C" int GameResources_ClearTertiaryFlags(...);
extern "C" int GameResources_ClearSecondaryFlags(...);
extern "C" int GameResources_ClearPrimaryFlags(...);
extern "C" int GameResources_GetInstance(...);
extern "C" int GameResources_SetSecondaryFlags(...);
extern "C" int Zone3D_GetMainInstance(...);
extern "C" int TextContext_GetSharedInstance(...);
extern "C" int GameResources_SetTertiaryFlags(...);
extern "C" int GameResources_SetPrimaryFlags(...);
extern "C" int _ZN12ZoneFeatures8SetColorEt(...);
extern "C" int _ZN9GameState11GetInstanceEv(...);
extern "C" int Field_InitializeOverlayEightActivityRequest(...);
extern "C" void* memset(void*,int,unsigned);extern "C" void* memcpy(void*,const void*,unsigned);
// Original data: arm9/ov004 @ 0x2171030; symbol: data_ov004_02171030.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" char MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage[];
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov004 @ 0x02169144; symbol: RestoreResourceMasksColorAndLayoutByte; size: 0xc8.
extern "C" int ProfileMenu_RestoreScenePresentation(void){
_ZN9GameState11GetInstanceEv();char* resources=C(GameResources_GetInstance());void* record=P(resources,0x3b84);GameResources_ClearPrimaryFlags(resources,-1);GameResources_ClearSecondaryFlags(resources,-1);GameResources_ClearTertiaryFlags(resources,-1);GameResources_SetPrimaryFlags(resources,W(P(MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage,0),0x180));GameResources_SetSecondaryFlags(resources,W(P(MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage,0),0x184));GameResources_SetTertiaryFlags(resources,W(P(MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage,0),0x188));char* global=C(Zone3D_GetMainInstance());if(!global)return 0;char* features=global+108;if(!features)return 0;_ZN12ZoneFeatures8SetColorEt(features,H(P(MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage,0),0x18c));Field_InitializeOverlayEightActivityRequest(record,-1);B(C(TextContext_GetSharedInstance()),0x1962)=0;return 0;
}
