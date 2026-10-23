#include <globaldefs.h>
ARM
#pragma force_active on

struct BottomButtonBar { void *buttons[2]; void *background; };
// Original data: arm9/ov031 @ 0x02250BA8; symbol: data_ov031_02250ba8.
// Zero-initialized context pointer; the background sprite group is at offset eight.
extern "C" BottomButtonBar *WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage;
extern "C" void WfcUtility_GetSpriteGroupPosition(void *, int, unsigned *, int *);
extern "C" void Graphics_SetSharedModeEntriesFromTables(int);
extern "C" void WfcUtility_SetTaskCallback(void *, void (*)(void *));
extern "C" void System_AdvanceFourStepCounterAndSetCallback(void *);
// Original: arm9/ov031 @ 0x02222F44; symbol: func_ov031_02222f44; size: 0x6C.
// Moves the bottom button bar up four pixels, clamps it at 168 and schedules the input delay.
extern "C" void WfcUtility_SlideBottomButtonBarIn(void *task)
{
    unsigned x;
    int y;
    WfcUtility_GetSpriteGroupPosition(WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage->background, 0, &x, &y);
    y -= 4;
    Graphics_SetSharedModeEntriesFromTables(y);
    if (y > 168) return;
    Graphics_SetSharedModeEntriesFromTables(168);
    WfcUtility_SetTaskCallback(task, System_AdvanceFourStepCounterAndSetCallback);
}
#pragma force_active reset
