#include <globaldefs.h>
ARM

extern "C" void _ZN23ZoneContainerRenderPart5ResetEv(void *);
extern "C" void BattleCombo_ClearIndicatorState(unsigned char *record);

// Original: arm9/ov000 @ 0x02182114; symbol: func_ov000_02182114; size: 0x38.
extern "C" void ResetZoneContainerRenderParts(void *container) {
    for (int i = 0; i < 13; i++) {
        _ZN23ZoneContainerRenderPart5ResetEv((char *)container + i * 0x88);
    }
    BattleCombo_ClearIndicatorState((unsigned char *)container + 0x6e8);
}
