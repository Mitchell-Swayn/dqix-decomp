#include <globaldefs.h>
#include <Graphics/Vector.h>
ARM
#pragma force_active on
// Original: arm9/ov005 @ 0x021538FC; symbol: func_ov005_021538fc; size: 0x58.
// Approaches one Q12 cursor coordinate, snapping within the per-frame threshold.
extern "C" void EquipmentMenu_ApproachCursorCoordinate(void *, const int *target, int *current, int factor, int threshold)
{
    int difference = *target - *current;
    if (fix32abs(difference) < threshold) {
        *current = *target;
    } else {
        difference = (int)(((long long)difference * factor + 0x800) >> 12);
        *current = *current + difference;
    }
}
