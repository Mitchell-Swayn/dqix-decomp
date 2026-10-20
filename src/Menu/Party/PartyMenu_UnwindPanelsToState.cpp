#include <globaldefs.h>
ARM
extern "C" unsigned Window_GetCanvasStackDepth(char*);
extern "C" void PartyMenu_PopPanelGroupAndRestoreSelection(void*);
// Original: arm9/ov002 @ 0x02156FF0; symbol: func_ov002_02156ff0; size: 0x40.
extern "C" unsigned PartyMenu_UnwindPanelsToState(char* self, unsigned value) {
    unsigned count;
    while ((count = Window_GetCanvasStackDepth(self + 0xec8)) != 0) {
        unsigned current = *(unsigned*)(self + 0x1bb8);
        if (current == value) return current;
        PartyMenu_PopPanelGroupAndRestoreSelection(self);
    }
    return count;
}
