#include <globaldefs.h>
ARM
#pragma optimization_level 4
#pragma optimize_for_size off
#pragma force_active on

struct AccessPointList {
    void *rows; void *resources[13]; void *scrollTask; void *inputTask;
    unsigned short scrollSpan; unsigned char padding42[14];
    signed char pressedRow; unsigned char rowCount,selectedRow,scrollDivisor,mode,repeatDelay,unused56,dragging,limitSound,released;
};
struct AccessPointOwner {unsigned char selected; unsigned char padding; unsigned short scroll; AccessPointList *list;};
extern "C" {
// Original data: arm9/ov031 @ 0x02290C8C; selected row, scroll and allocated list state.
extern AccessPointOwner TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage;
void WfcUtility_PlaySequenceArchiveEntry(unsigned);
void WfcUtility_UpdateAccessPointSelectionHighlight();
}
#define OWNER TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage
#define LIST OWNER.list
extern "C" {
// Original data: arm9/ov031 @ 0x02248E5C; five four-coordinate touch rectangles.
extern unsigned short WfcUtilityHandleAccessPointListInput_AccessPointSelectionTouchRectanglesFiveEightByteEntries[5][4];
// Original data: arm9/ov031 @ 0x022493B8; scrollbar touch rectangle.
extern unsigned short WfcScrollbarUpdateThumbDrag_UnknownRoleInitializedBytes[4];
int WfcUtility_IsTouchPressInsideRectangle(unsigned short*);
int System_IsTouchInsideRectangle(unsigned short*);
int WfcUtility_AreButtonsPressed(unsigned);
bool WfcUtility_AreButtonsPressedOrRepeating(unsigned);
int WfcUtility_AreButtonsReleased(unsigned);
void WfcUtility_LatchBottomButtonSelection(signed char);
void WfcScrollbar_DisableTouchInput();
void Util_HandleChangedContextSelection();
void System_UpdateSharedStateBranch();
void WfcUtility_MoveAccessPointListSelection(int);
}

// Original: arm9/ov031 @ 0x0222BB58; symbol: func_ov031_0222bb58; size: 0x254.
// Handles touch row selection and button navigation while the access-point list is idle.
extern "C" void WfcUtility_HandleAccessPointListInput()
{
    if (LIST->scrollTask || LIST->dragging) return;
    if (WfcUtility_IsTouchPressInsideRectangle(WfcScrollbarUpdateThumbDrag_UnknownRoleInitializedBytes)) {
        LIST->pressedRow=-1;
        for (int i=0;(unsigned)i<5;++i) {
            if (WfcUtility_IsTouchPressInsideRectangle(WfcUtilityHandleAccessPointListInput_AccessPointSelectionTouchRectanglesFiveEightByteEntries[i])) {
                if (i<4) {LIST->pressedRow=i; break;}
                WfcUtility_LatchBottomButtonSelection(1); OWNER.selected=i; WfcUtility_UpdateAccessPointSelectionHighlight(); return;
            }
        }
    }
    if (System_IsTouchInsideRectangle(WfcScrollbarUpdateThumbDrag_UnknownRoleInitializedBytes)) {
        unsigned short (*rectangle)[4]=WfcUtilityHandleAccessPointListInput_AccessPointSelectionTouchRectanglesFiveEightByteEntries;
        for (int i=0;i<4;++i,++rectangle) {
            if (System_IsTouchInsideRectangle(*rectangle)) {
                if (LIST->pressedRow!=i) break;
                if (i>=LIST->rowCount) {WfcUtility_PlaySequenceArchiveEntry(9); break;}
                WfcUtility_LatchBottomButtonSelection(1); OWNER.selected=i; WfcUtility_UpdateAccessPointSelectionHighlight(); return;
            }
        }
    }
    if (WfcUtility_AreButtonsPressed(1)) {WfcUtility_LatchBottomButtonSelection(1); WfcScrollbar_DisableTouchInput(); return;}
    if (WfcUtility_AreButtonsPressed(2)) {WfcUtility_LatchBottomButtonSelection(0); return;}
    if (WfcUtility_AreButtonsPressedOrRepeating(0x200)) {Util_HandleChangedContextSelection(); return;}
    if (WfcUtility_AreButtonsReleased(0x200)) {LIST->released=0; return;}
    if (WfcUtility_AreButtonsPressedOrRepeating(0x100)) {System_UpdateSharedStateBranch(); return;}
    if (WfcUtility_AreButtonsReleased(0x100)) {LIST->released=0; return;}
    if (WfcUtility_AreButtonsPressedOrRepeating(0x40)) {WfcUtility_MoveAccessPointListSelection(1); return;}
    if (WfcUtility_AreButtonsReleased(0x40)) {LIST->released=0; return;}
    if (WfcUtility_AreButtonsPressedOrRepeating(0x80)) {WfcUtility_MoveAccessPointListSelection(3); return;}
    if (WfcUtility_AreButtonsReleased(0x80)) LIST->released=0;
}
#pragma force_active reset
