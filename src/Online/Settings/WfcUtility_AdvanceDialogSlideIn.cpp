#include <globaldefs.h>
ARM
#pragma force_active on
struct SlidingDialog { void* primary; unsigned char padding[16]; void* task; unsigned char padding18[4]; unsigned char kind; };
extern "C" {
// Original data: arm9/ov031 @ 0x02290d10; symbol: data_ov031_02290d10; initially zero, dialog pointer.
extern SlidingDialog* WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x02249336; symbol: data_ov031_02249336; per-kind target Y positions with a four-byte stride.
extern const unsigned short WfcUtilityAdvanceDialogSlideIn_UnknownRoleInitializedBytes[][2];
void WfcUtility_GetSpriteGroupPosition(void*,int,int*,int*);
void WfcUtility_SetDialogVerticalPosition(int);
void WfcUtility_WaitForDialogAutoDismiss();
void Graphics_SelectModeRectangleAndConfigureSprite();
void* WfcUtility_CreateTaskWithBorrowedContext(unsigned,void (*)(),void*,unsigned);
void WfcUtility_RequestTaskRemoval(unsigned,void*);
}
// Original: arm9/ov031 @ 0x02237f2c; symbol: func_ov031_02237f2c; size: 0xd4.
// Slides the dialog upward by twelve pixels, clamps its destination, and replaces the animation with its input task.
extern "C" void WfcUtility_AdvanceDialogSlideIn(void* task)
{
    int x,y;
    WfcUtility_GetSpriteGroupPosition(WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage->primary,0,&x,&y);
    y-=12;
    int target=WfcUtilityAdvanceDialogSlideIn_UnknownRoleInitializedBytes[WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage->kind][0];
    if (y>target) { WfcUtility_SetDialogVerticalPosition(y); return; }
    WfcUtility_SetDialogVerticalPosition(target);
    if (WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage->kind==5)
        WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage->task=WfcUtility_CreateTaskWithBorrowedContext(0,WfcUtility_WaitForDialogAutoDismiss,0,120);
    else
        WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage->task=WfcUtility_CreateTaskWithBorrowedContext(0,Graphics_SelectModeRectangleAndConfigureSprite,0,120);
    WfcUtility_RequestTaskRemoval(1,task);
}
#pragma force_active reset
