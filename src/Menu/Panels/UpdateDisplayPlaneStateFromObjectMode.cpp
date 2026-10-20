#include <globaldefs.h>
ARM
extern "C" void Graphics_ApplySubBackgroundSnapshotAndClearPending(void*);
extern "C" void Graphics_ApplyMainBackgroundSnapshotAndClearPending(void*);
// Original: arm9/ov023 @ 0x021DCD18; symbol: UpdateDisplayPlaneStateFromObjectMode; size: 0x60.
// Resets or processes object +0x118 according to state byte +0x77C, then updates display register bits 8-12 from field +0x730.
extern "C" void UpdateDisplayPlaneStateFromObjectMode(char* p) {
    char* object = p + 0x118;
    if (*(signed char*)(p + 0x77c) == 1) {
        Graphics_ApplySubBackgroundSnapshotAndClearPending(object);
        unsigned int control = *(volatile unsigned int*)0x04001000;
        control = (control & ~0x1f00u) | (*(unsigned int*)(p + 0x730) << 8);
        *(volatile unsigned int*)0x04001000 = control;
    } else {
        Graphics_ApplyMainBackgroundSnapshotAndClearPending(object);
        unsigned int control = *(volatile unsigned int*)0x04000000;
        control = (control & ~0x1f00u) | (*(unsigned int*)(p + 0x730) << 8);
        *(volatile unsigned int*)0x04000000 = control;
    }
}
