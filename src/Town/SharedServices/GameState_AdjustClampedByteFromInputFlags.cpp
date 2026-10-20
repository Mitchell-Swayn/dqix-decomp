#include <globaldefs.h>
ARM
extern "C" void Tavern_PopulateDiscoveredSessionList(void);
// Original: arm9/ov003 @ 0x0216664C; symbol: func_ov003_0216664c; size: 0x78.
extern "C" void GameState_AdjustClampedByteFromInputFlags(void *object) {
    unsigned flags = *(unsigned *)((char *)object + 0x45c);
    int changed = 0;
    if (flags & 0x10) {
        *(signed char *)((char *)object + 0x4a0) += 1;
        changed = 1;
        goto clamp;
    }
    if (flags & 0x20) {
        *(signed char *)((char *)object + 0x4a0) -= 1;
        changed = 1;
    }
clamp:
    if (*(signed char *)((char *)object + 0x4a0) >= 2) *(signed char *)((char *)object + 0x4a0) = 0;
    else if (*(signed char *)((char *)object + 0x4a0) < 0) *(signed char *)((char *)object + 0x4a0) = 1;
    if (changed) Tavern_PopulateDiscoveredSessionList();
}
