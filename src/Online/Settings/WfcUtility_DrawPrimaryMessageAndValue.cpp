#include <globaldefs.h>
ARM
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
extern "C" unsigned Graphics_CreateBG0CanvasForScreen(...);
extern "C" unsigned WfcUtility_MarkBackgroundTextCanvasDirty(...);
extern "C" unsigned WfcUtility_GetLanguage(...);
extern "C" unsigned WfcUtility_GetLanguageMessageLayoutParameter(...);
extern "C" unsigned WfcUtility_GetMessageText(...);
extern "C" unsigned WfcUtility_RenderCanvasAnchoredText(...);
extern "C" unsigned WfcUtility_RenderCanvasAlignedText(...);
// Original data: arm9/ov031 @ 0x2248974; symbol: data_ov031_02248974.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 6b00.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityDrawPrimaryMessageAndValue_UnknownRoleInitializedBytes[];
// Original data: arm9/ov031 @ 0x2248976; symbol: data_ov031_02248976.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 22006c0022007c0022005d0022005f0022007d00220050002200.
// Observed span: 26 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityDrawPrimaryMessageAndValue_UnknownRoleInitializedBytes_Variant2[];
// Original data: arm9/ov031 @ 0x2290c4c; symbol: data_ov031_02290c4c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityCreateSlidingDialog_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02223614; symbol: CreatePrimaryCanvasAndSubmitMenuRecord; size: 0xbc.
// Creates primary canvas, submits resolved record and indexed geometry, marks buffer ready.
extern "C" void WfcUtility_DrawPrimaryMessageAndValue(unsigned selection,unsigned index){
 unsigned canvas=Graphics_CreateBG0CanvasForScreen(0,0);unsigned record=WfcUtility_GetMessageText(U(WfcUtilityCreateSlidingDialog_UnknownRoleZeroInitializedStorage,0),index);unsigned value=WfcUtility_GetLanguageMessageLayoutParameter();WfcUtility_RenderCanvasAlignedText(canvas,13,60,230,94,2,value,record);
 unsigned first=WfcUtility_GetLanguage();unsigned second=WfcUtility_GetLanguage();WfcUtility_RenderCanvasAnchoredText(canvas,H(WfcUtilityDrawPrimaryMessageAndValue_UnknownRoleInitializedBytes,first*4),H(WfcUtilityDrawPrimaryMessageAndValue_UnknownRoleInitializedBytes_Variant2,second*4),2,0x209,selection);WfcUtility_MarkBackgroundTextCanvasDirty(canvas);
}
