#include <globaldefs.h>
ARM
#pragma optimization_level 4
struct Path25{char text[25];};struct Path22{char text[22];};
extern "C" const Path25 Graphics_LoadProgressScreenResourcesAndPriorities_PathCharXb4ApListBackNscL;
extern "C" const Path22 Graphics_LoadProgressScreenResourcesAndPriorities_PathCharYbBgStep31NclL;
// Original data: arm9/ov031 @ 0x2290c8c; symbol: data_ov031_02290c8c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char Graphics_LoadProgressScreenResourcesAndPriorities_PathCharJb4ApListNscL[],TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage[];
extern "C" char* WfcUtility_LocalizeResourcePath(const char*);
extern "C" void WfcUtility_LoadLocalizedResourceAndApply(void*,void(*)(void*,int,unsigned));
extern "C" void LoadToMainBG3ScreenData(const void*,unsigned,unsigned);
extern "C" void WfcUtility_CreateDeferredBackgroundTilemap(void*);
extern "C" void WfcUtility_MarkBackgroundTilemapDirty();
extern "C" void* WfcUtility_LoadArchiveResource(const char*,unsigned*,int);
// Original: arm9/ov031 @ 0x0222B71C; symbol: func_ov031_0222b71c; size: 0x154.
// Loads two progress-screen resources and assigns background priority bits on both displays.
extern "C" void Graphics_LoadProgressScreenResourcesAndPriorities(){
Path25 first=Graphics_LoadProgressScreenResourcesAndPriorities_PathCharXb4ApListBackNscL;Path22 second=Graphics_LoadProgressScreenResourcesAndPriorities_PathCharYbBgStep31NclL;
WfcUtility_LoadLocalizedResourceAndApply(Graphics_LoadProgressScreenResourcesAndPriorities_PathCharJb4ApListNscL,(void(*)(void*,int,unsigned))LoadToMainBG3ScreenData);
*(void**)(*(char**)(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage+4)+4)=WfcUtility_LoadArchiveResource(WfcUtility_LocalizeResourcePath(first.text),0,4);
WfcUtility_CreateDeferredBackgroundTilemap(*(void**)(*(char**)(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage+4)+4));WfcUtility_MarkBackgroundTilemapDirty();
*(void**)(*(char**)(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage+4)+8)=WfcUtility_LoadArchiveResource(WfcUtility_LocalizeResourcePath(second.text),0,4);
volatile unsigned short* sub=(volatile unsigned short*)0x4001008;
volatile unsigned short* main=(volatile unsigned short*)0x400000a;
sub[0]=(sub[0]&~3)|3;sub[1]=(sub[1]&~3)|3;
*(volatile unsigned short*)0x4000008=(*(volatile unsigned short*)0x4000008&~3)|3;
main[0]=(main[0]&~3)|2;main[1]=(main[1]&~3)|3;main[2]=(main[2]&~3)|2;
}
