struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);
extern "C" void* Window_GetUnusedCanvasSlotForId(void*, int);
extern "C" void DisplayRecord_SetActiveAndResetSelection(void*, int),DisplayRecord_SetPrimarySelectionAndMarkDirty(void*, unsigned char),DisplayRecord_SetSecondarySelectionAndMarkDirty(void*, unsigned char);
// Configure an existing or newly obtained screen element. Zero height disables it.
// Original: arm9/ov012 @ 0x021842A0; symbol: func_ov012_021842a0; size: 0x8C.
extern "C" void ProfileEditor_UpdatePageIndicator(unsigned char* screen, int id, int width, int height) {
    void* element = (void*)Window_FindActiveCanvasById((WindowCanvasOwner*)(screen + 0xac),id);
    if (!element) {
        element = Window_GetUnusedCanvasSlotForId(screen + 0xac, id);
        if (!element) return;
    }
    if (height) {
        DisplayRecord_SetActiveAndResetSelection(element, 1);
        DisplayRecord_SetPrimarySelectionAndMarkDirty(element, (unsigned char)width);
        DisplayRecord_SetSecondarySelectionAndMarkDirty(element, (unsigned char)height);
    } else {
        DisplayRecord_SetActiveAndResetSelection(element, 0);
        DisplayRecord_SetPrimarySelectionAndMarkDirty(element, 0);
        DisplayRecord_SetSecondarySelectionAndMarkDirty(element, 0);
    }
}
