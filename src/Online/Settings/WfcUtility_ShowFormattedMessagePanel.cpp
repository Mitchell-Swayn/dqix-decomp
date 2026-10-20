#include <globaldefs.h>
#include <System/LoadToVRAM.h>
ARM
// Original data: arm9/ov031 @ 0x2250bac; symbol: data_ov031_02250bac.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2290c4c; symbol: data_ov031_02290c4c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char OverlayProcessPendingFlag_UnknownRoleZeroInitializedStorage[]; extern "C" unsigned char WfcUtility_ShowFormattedMessagePanel_PathCharJtNullNscL[]; extern "C" unsigned char WfcUtilityCreateSlidingDialog_UnknownRoleZeroInitializedStorage[]; extern "C" void WfcUtility_LoadLocalizedResourceAndApply(void*,void(*)(const void*,unsigned,unsigned)); extern "C" void *Graphics_CreateBG0CanvasForScreen(int,int); extern "C" char *WfcUtility_GetMessageTextAndInsertDigit(void*,unsigned,int,int); extern "C" unsigned int WfcUtility_GetLanguageMessageLayoutParameter(void); extern "C" void WfcUtility_RenderCanvasAlignedText(void*,int,int,int,int,int,unsigned,unsigned); extern "C" void WfcUtility_MarkBackgroundTextCanvasDirty(void*);
// Original: arm9/ov031 @ 0x0222336C; symbol: InitializeMappedPaletteScreenAndCallback. Initializes shared screen resources and registers a callback.
extern "C" int WfcUtility_ShowFormattedMessagePanel(unsigned index,int position,int value) { if(OverlayProcessPendingFlag_UnknownRoleZeroInitializedStorage[0])return 0; WfcUtility_LoadLocalizedResourceAndApply(WfcUtility_ShowFormattedMessagePanel_PathCharJtNullNscL,LoadToSubBG0ScreenData); *(volatile unsigned int *)0x04001010=0x01920000; void *canvas=Graphics_CreateBG0CanvasForScreen(1,0);char *table=*(char **)WfcUtilityCreateSlidingDialog_UnknownRoleZeroInitializedStorage; char *entry=WfcUtility_GetMessageTextAndInsertDigit(table,index,position,value); unsigned int state=WfcUtility_GetLanguageMessageLayoutParameter();WfcUtility_RenderCanvasAlignedText(canvas,0x14,0,0xd8,0x40,2,state,(unsigned)entry); WfcUtility_MarkBackgroundTextCanvasDirty(canvas); OverlayProcessPendingFlag_UnknownRoleZeroInitializedStorage[0]=1; return 1; }
