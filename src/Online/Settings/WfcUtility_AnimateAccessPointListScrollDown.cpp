#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290c8c; symbol: data_ov031_02290c8c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" {struct Shared {unsigned short a,offset;char* p;};extern Shared TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage;void WfcScrollbar_DisableTouchInput(void*);void Overlay_ClearFourSharedObjects();int FastIntModulus(int,int);void Graphics_UpdateFivePairedSpriteRows();void Graphics_UpdateFiveVisibleEntriesInTwoPasses();int FastIntDivide(int,int);void WfcScrollbar_SetThumbOffset();void WfcScrollbar_EnableTouchInput();void WfcUtility_UpdateAccessPointSelectionHighlight();void WfcUtility_RequestTaskRemoval(unsigned,void*);}
// Original: arm9/ov031 @ 0x0222C7D8; symbol: AdvanceSharedRowOffsetByFour; size: 0x98.
// Advances shared row offset4, wraps28 boundary and refreshes paired rows.
extern "C" void WfcUtility_AnimateAccessPointListScrollDown(void* self){WfcScrollbar_DisableTouchInput(self);Overlay_ClearFourSharedObjects();TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage.offset+=4;int remainder=FastIntModulus(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage.offset,28);if(remainder>=4){Graphics_UpdateFivePairedSpriteRows();return;}TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage.offset-=remainder;Graphics_UpdateFiveVisibleEntriesInTwoPasses();char* p=TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage.p;FastIntDivide(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage.offset*(unsigned char)p[0x53],*(unsigned short*)(p+0x40));WfcScrollbar_SetThumbOffset();WfcScrollbar_EnableTouchInput();WfcUtility_UpdateAccessPointSelectionHighlight();*(int*)(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage.p+0x38)=0;WfcUtility_RequestTaskRemoval(0,self);}
