#include <globaldefs.h>
ARM
extern "C" unsigned int *FindPackedThresholdEntry(void *, int);
// Original: arm9/ov023 @ 0x021F5578; symbol: func_ov023_021f5578; size: 0x20.
extern "C" unsigned int ExperienceAdjustment_GetLevelBiasForReward(void *arg0, int arg1, unsigned int fallback) {
    unsigned int value = fallback;
    unsigned int *result = FindPackedThresholdEntry(arg0, arg1);
    if (result != 0)
        value = *result >> 26;
    return value;
}
