#include <globaldefs.h>
ARM
extern "C" void _ZN23ZoneContainerRenderPart12ResetIfFlag0Ev(void*);
extern "C" void BattleCombo_ClearIndicatorState(unsigned char *record);
// Original: arm9/ov000 @ 0x021823A4; symbol: func_ov000_021823a4; size: 0x38.
extern "C" void ZoneContainer_ResetRenderParts(void *self) {
    for (int i = 0; i < 13; ++i) {
        _ZN23ZoneContainerRenderPart12ResetIfFlag0Ev((unsigned char *)self + i * 0x88);
    }
    BattleCombo_ClearIndicatorState((unsigned char *)self + 0x6e8);
}
