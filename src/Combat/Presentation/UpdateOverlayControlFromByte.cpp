#include <globaldefs.h>
ARM
extern "C" void *BattleScene_GetActiveInstance(void);
extern "C" void CombatScene_RestoreZoneOverridesWhenParityChanges(void *, int);
extern "C" void ApplyZoneOverridesAndRecordParity(void *, int);
// Original: arm9/ov025 @ 0x021E82E4; symbol: func_ov025_021e82e4; size: 0x30.
extern "C" int UpdateOverlayControlFromByte(void *parameter) {
    void *control = BattleScene_GetActiveInstance();
    int enabled = *((unsigned char *)parameter + 8);
    if (enabled != 0)
        CombatScene_RestoreZoneOverridesWhenParityChanges(control, 1);
    else
        ApplyZoneOverridesAndRecordParity(control, enabled);
    return 1;
}
