#include <globaldefs.h>
ARM
extern "C" void BattleCamera_ResetShotAndTransitions(void *, unsigned int, unsigned int, unsigned int);
extern "C" void Camera_EnableParentTransform(void *, int);
// Original: arm9/ov000 @ 0x0216D530; symbol: Object_SetField224AndUpdateBit168Flag; size: 0x30.
// Stores the signed value at object+0x224 and updates the bit-1 flag at +0x168, calling the reset helper for negative values.
extern "C" void BattleCamera_SetTrackedCombatant(void *obj, int value) {
    if (value < 0) BattleCamera_ResetShotAndTransitions(obj, 1, 1, 1);
    else Camera_EnableParentTransform(obj, value);
    *(int *)((char *)obj + 0x224) = value;
}
