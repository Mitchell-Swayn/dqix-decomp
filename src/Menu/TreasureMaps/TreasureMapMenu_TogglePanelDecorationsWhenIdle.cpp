#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
// Original data: arm9/ov004 @ 0x2171010; symbol: data_ov004_02171010.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct GameResources;extern "C" GameResources* GameResources_GetInstance();extern "C" bool GameResources_IsSelectedScreenBrightnessNeutral(char*,int);extern "C" unsigned TextContext_GetSharedInstance();extern "C" char* PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage;extern "C" void TreasureMapPanel_SetDecorationsVisible(void*,unsigned char);extern "C" int TreasureMapMenu_UpdateDecorationModeIndicators(void*);extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);extern "C" char Main_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov004 @ 0x021652E8; symbol: Graphics_ApplyPairModeAfterTransitionsComplete; size: 0xFC.
extern "C" int TreasureMapMenu_TogglePanelDecorationsWhenIdle(void* self){char* resources=(char*)GameResources_GetInstance();if(!GameResources_IsSelectedScreenBrightnessNeutral(resources,0)||!GameResources_IsSelectedScreenBrightnessNeutral(resources,1))return 0;if(W((void*)TextContext_GetSharedInstance(),0x998))return 0;char* record=PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage;if(!B(record,0x18f4))return 0;if(B(record,0x18fc)==0)B(record,0x18fc)=1;else if(B(record,0x18fc)==1)B(record,0x18fc)=0;void* owner=P(GameResources_GetInstance(),0x36d0);unsigned mode=B(PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage,0x18fc);if(mode==1)TreasureMapPanel_SetDecorationsVisible(owner,0);else if(mode==0)TreasureMapPanel_SetDecorationsVisible(owner,1);TreasureMapMenu_UpdateDecorationModeIndicators(self);SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);return 0;}
