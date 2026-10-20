#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F2348; symbol: func_ov023_021f2348; size: 0x20.
extern "C" void MenuNotice_SetFinalEntryProgressGate(void *a0, int enabled) {
    char *object = (char *)a0;
    object += 0x400;
    if (enabled)
        *(unsigned short *)(object + 0x38) |= 0x400;
    else
        *(unsigned short *)(object + 0x38) &= ~0x400;
}
