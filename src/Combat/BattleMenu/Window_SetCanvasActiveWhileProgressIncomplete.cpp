struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);
extern "C" void DisplayRecord_SetActiveAndResetSelection(unsigned char *self, unsigned value);
// Original: arm9/ov000 @ 0x0217A9D0; symbol: func_ov000_0217a9d0; size: 0x38.
extern "C" void Window_SetCanvasActiveWhileProgressIncomplete(int id, int stopIndex, int progress, void *owner) {
    unsigned char *record = (unsigned char *)(void *)Window_FindActiveCanvasById((WindowCanvasOwner*)(owner), (unsigned)id);
    if (!record) return;
    unsigned value = 0;
    if (progress < stopIndex) value = 1;
    DisplayRecord_SetActiveAndResetSelection(record, value);
}
