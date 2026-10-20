#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original data: arm9/ov031 @ 0x2290cc0; symbol: data_ov031_02290cc0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char Graphics_LoadSecondaryPlaneResourcesAndConfigurePriorities_PathCharYbBgStep11NclL[],Graphics_LoadSecondaryPlaneResourcesAndConfigurePriorities_PathCharYbObjWayNclL[],Graphics_LoadSecondaryPlaneResourcesAndConfigurePriorities_PathCharJbBgStep1NcgL[],Graphics_LoadSecondaryPlaneResourcesAndConfigurePriorities_PathCharJbBgStep1NclL[],Graphics_LoadSecondaryPlaneResourcesAndConfigurePriorities_PathCharJb2ApNscL[],ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage[];extern "C" void LoadToMainObjStandardPalette(void*,int,unsigned),LoadToMainBG2CharacterData(void*,int,unsigned),LoadToMainBGStandardPalette(void*,int,unsigned),LoadToMainBG2ScreenData(void*,int,unsigned);extern "C" void WfcUtility_LoadLocalizedResourceAndApply(void*,void(*)(void*,int,unsigned));extern "C" char* WfcUtility_LocalizeResourcePath(const char*);extern "C" void* WfcUtility_LoadArchiveResource(const char*,unsigned*,int);extern "C" void WfcUtility_EnableDisplayPlanes(int,unsigned);
// Original: arm9/ov031 @ 0x02232568; symbol: Graphics_LoadSecondaryPlaneResourcesAndConfigurePriorities; size 0x110.
extern "C" void Graphics_LoadSecondaryPlaneResourcesAndConfigurePriorities(){struct Path{char text[22];};Path path=*(Path*)Graphics_LoadSecondaryPlaneResourcesAndConfigurePriorities_PathCharYbBgStep11NclL;WfcUtility_LoadLocalizedResourceAndApply(Graphics_LoadSecondaryPlaneResourcesAndConfigurePriorities_PathCharYbObjWayNclL,LoadToMainObjStandardPalette);WfcUtility_LoadLocalizedResourceAndApply(Graphics_LoadSecondaryPlaneResourcesAndConfigurePriorities_PathCharJbBgStep1NcgL,LoadToMainBG2CharacterData);WfcUtility_LoadLocalizedResourceAndApply(Graphics_LoadSecondaryPlaneResourcesAndConfigurePriorities_PathCharJbBgStep1NclL,LoadToMainBGStandardPalette);WfcUtility_LoadLocalizedResourceAndApply(Graphics_LoadSecondaryPlaneResourcesAndConfigurePriorities_PathCharJb2ApNscL,LoadToMainBG2ScreenData);P(P(ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage,4),0)=(char*)WfcUtility_LoadArchiveResource(WfcUtility_LocalizeResourcePath(path.text),0,4);WfcUtility_EnableDisplayPlanes(1,16);volatile unsigned short* a=(volatile unsigned short*)0x4001008;volatile unsigned short* b=(volatile unsigned short*)0x400000a;a[0]=(a[0]&~3)|3;a[1]=(a[1]&~3)|3;b[0]=(b[0]&~3)|3;b[1]=(b[1]&~3)|3;}
