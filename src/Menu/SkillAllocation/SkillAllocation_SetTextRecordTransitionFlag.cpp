struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);
extern "C" void Graphics_FormatFiveRowSelectionTextAndRefreshOwner(void *);
// Original: arm9/ov013 @ 0x02186C64; symbol: func_ov013_02186c64; size: 0x48.
extern "C" void SkillAllocation_SetTextRecordTransitionFlag(void *owner, unsigned int id, int enabled) {
    void *record = (void *)Window_FindActiveCanvasById((WindowCanvasOwner*)((char *)owner + 0x38), id);
    if (record == 0) return;
    unsigned char *flags = (unsigned char *)record + 0xc5;
    if (enabled) *flags |= 0x40;
    else *flags = *flags & 0xffffffbf;
    if (id != 0) return;
    Graphics_FormatFiveRowSelectionTextAndRefreshOwner(owner);
}
