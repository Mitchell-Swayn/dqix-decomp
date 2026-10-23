#include <globaldefs.h>
ARM
#pragma force_active on
struct AccessPointListState {
    unsigned char padding[0x38]; unsigned touchState; unsigned padding3c; unsigned short scrollRange;
    unsigned char padding42[0x11]; unsigned char scrollScale;
};
struct AccessPointScroll { unsigned short unused,position; AccessPointListState* state; };
extern "C" {
// Original data: arm9/ov031 @ 0x02290c8c; symbol: data_ov031_02290c8c; zero-initialized list scroll state.
extern AccessPointScroll TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage;
void WfcScrollbar_DisableTouchInput(); void Overlay_ClearFourSharedObjects();
int FastIntModulus(int,int); int FastIntDivide(int,int);
void Graphics_UpdateFiveVisibleEntriesInTwoPasses(); void Graphics_UpdateFivePairedSpriteRows();
void WfcScrollbar_SetThumbOffset(unsigned); void WfcScrollbar_EnableTouchInput();
void WfcUtility_UpdateAccessPointSelectionHighlight(); void WfcUtility_RequestTaskRemoval(unsigned,void*);
}
// Original: arm9/ov031 @ 0x0222c71c; symbol: func_ov031_0222c71c; size: 0xbc.
// Moves the list upward four pixels, refreshes rows at the wrap boundary, and restores touch on alignment.
extern "C" void WfcUtility_AnimateAccessPointListScrollUp(void* task,void*)
{
    WfcScrollbar_DisableTouchInput();
    Overlay_ClearFourSharedObjects();
    if (TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage.position>4)
        TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage.position-=4;
    else
        TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage.position=0;
    int remainder=FastIntModulus(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage.position,28);
    if (remainder==24) { Graphics_UpdateFiveVisibleEntriesInTwoPasses(); return; }
    if (remainder>24) {
        TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage.position+=28-remainder;
        remainder=0;
    }
    Graphics_UpdateFivePairedSpriteRows();
    if (remainder) return;
    WfcScrollbar_SetThumbOffset(FastIntDivide(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage.position*TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage.state->scrollScale,TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage.state->scrollRange));
    WfcScrollbar_EnableTouchInput();
    WfcUtility_UpdateAccessPointSelectionHighlight();
    TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage.state->touchState=0;
    WfcUtility_RequestTaskRemoval(0,task);
}

#pragma force_active reset
