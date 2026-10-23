#include <globaldefs.h>
ARM
#pragma force_active on

struct BottomButtonBar { void *buttons[2]; void *background; };
// Original data: arm9/ov031 @ 0x02250BA8; symbol: data_ov031_02250ba8.
// Zero-initialized context pointer; the background sprite group is at offset eight.
extern "C" BottomButtonBar *WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage;
extern "C" void WfcUtility_GetSpriteGroupPosition(void *, int, unsigned *, int *);
extern "C" void Graphics_SetSharedModeEntriesFromTables(int);
extern "C" void WfcUtility_SetTaskCallback(void*,void (*)(void*,void*));
extern "C" void WfcUtility_DestroyBottomButtonBar(void*,void*);
// Original: arm9/ov031 @ 0x0222318C; symbol: func_ov031_0222318c; size: 0x64.
// Moves the bottom button bar down four pixels and schedules destruction when it leaves the screen.
extern "C" void WfcUtility_SlideBottomButtonBarOut(void* task,void*)
{
    unsigned x;
    int y;
    WfcUtility_GetSpriteGroupPosition(WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage->background, 0, &x, &y);
    y += 4;
    Graphics_SetSharedModeEntriesFromTables(y);
    if (y < 192) return;
    WfcUtility_SetTaskCallback(task, WfcUtility_DestroyBottomButtonBar);
}
#pragma force_active reset
