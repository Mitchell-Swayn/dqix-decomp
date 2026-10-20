#include <globaldefs.h>
ARM
struct Root {short pad;unsigned short offset;unsigned char* owner;};
// Original data: arm9/ov031 @ 0x2290c8c; symbol: data_ov031_02290c8c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" {extern Root TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage;int FastIntDivide(int,int);void Text_DrawSplitAsciiRow(int,int);void Graphics_UpdateIndexedSpriteTileFields(int,int);void Graphics_UpdateFivePairedSpriteRows();void WfcUtility_ClearTextCanvas(void*,int);void WfcUtility_MarkBackgroundTextCanvasDirty(void*);}
// Original: arm9/ov031 @ 0x0222C3B4; symbol: func_ov031_0222c3b4; size: 0xA8.
extern "C" void Graphics_UpdateFiveVisibleEntriesInTwoPasses(){
int count,current,i,start;
start=FastIntDivide(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage.offset,28);
count=TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage.owner[0x51];
WfcUtility_ClearTextCanvas(*(void**)(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage.owner+12),0);
if(count>5)count=5;
current=start;i=0;if(i<count)do{Text_DrawSplitAsciiRow(current,i);i++;current++;}while(i<count);
int j=0;if(j<count)do{Graphics_UpdateIndexedSpriteTileFields(start,j);j++;start++;}while(j<count);
WfcUtility_MarkBackgroundTextCanvasDirty(*(void**)(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage.owner+12));Graphics_UpdateFivePairedSpriteRows();
}
