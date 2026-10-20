#include <globaldefs.h>
ARM
extern "C" int FastIntDivide(...);
extern "C" int WfcUtility_MarkBackgroundTextCanvasDirty(...);
extern "C" int Graphics_DrawSharedRegionFieldByMode(...);
extern "C" int WfcSettingsList_UpdateRowOptionSprites(...);
extern "C" int WfcSettingsList_PositionVisibleRowSprites(...);
extern "C" int WfcUtility_MarkBackgroundTilemapDirty(...);
extern "C" int Overlay_CopyBlocksToGlobalTable(...);
extern "C" int WfcUtility_ClearTextCanvas(...);
extern "C" void* memset(void*,int,unsigned);extern "C" unsigned strlen(const char*);
// Original data: arm9/ov031 @ 0x2248f96; symbol: data_ov031_02248f96.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00006000e0004001c0014002a0022003a003.
// Observed span: 18 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char WfcSettingsListRedrawVisibleRows_UnknownRoleInitializedBytes[];
// Original data: arm9/ov031 @ 0x2290ca0; symbol: data_ov031_02290ca0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char StartMode6ContextCallback_UnknownRoleZeroInitializedStorage[];
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
// Original: arm9/ov031 @ 0x0222F9EC; symbol: RedrawFiveSharedRowsAndMarkBufferReady; size: 0xc0.
extern "C" void WfcSettingsList_RedrawVisibleRows(void){
int start=FastIntDivide(H(StartMode6ContextCallback_UnknownRoleZeroInitializedStorage,4),29);WfcUtility_ClearTextCanvas(P(P(StartMode6ContextCallback_UnknownRoleZeroInitializedStorage,8),20),0);int row=start;for(int i=0;i<5;i++,row++)Graphics_DrawSharedRegionFieldByMode(row,i);Overlay_CopyBlocksToGlobalTable(P(P(StartMode6ContextCallback_UnknownRoleZeroInitializedStorage,8),8)+H(WfcSettingsListRedrawVisibleRows_UnknownRoleInitializedBytes,start*2)*2,0,30,19);for(int i=0;i<5;i++,start++)WfcSettingsList_UpdateRowOptionSprites(start,i);WfcUtility_MarkBackgroundTilemapDirty();WfcUtility_MarkBackgroundTextCanvasDirty(P(P(StartMode6ContextCallback_UnknownRoleZeroInitializedStorage,8),20));WfcSettingsList_PositionVisibleRowSprites();
}
