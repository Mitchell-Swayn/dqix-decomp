#include <globaldefs.h>
ARM
extern "C" int Combat_CollectEligiblePartyIds(void *, void *, int, int);
extern "C" void Combat_SelectWeightedTargetCountFromPackedMode(void *, int, int, int *, short *);
// Original: arm9/ov024 @ 0x021EE378; symbol: LookupAndUpdateIndexedWorldValue; size: 0x70.
// Performs the indexed four-field lookup, stores its result, calls the follow-up updater for positive matches, then returns whether output halfword is nonnegative.
extern "C" int LookupAndUpdateIndexedWorldValue(void **source, int a, int b, int *resultOut, short *valueOut) {
    int result = Combat_CollectEligiblePartyIds(*source, valueOut, 4, 1);
    *resultOut = result;
    if (result <= 0)
        return 0;
    Combat_SelectWeightedTargetCountFromPackedMode(source, a, b, resultOut, valueOut);
    return *valueOut >= 0;
}
