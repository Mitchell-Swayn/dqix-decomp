#include <globaldefs.h>
ARM
extern short Combat_GetActionSummonedSpecies_SummonedSpeciesMappingRecords[];
// Original: arm9/ov000 @ 0x0215FB54; symbol: func_ov000_0215fb54; size: 0x48.
extern "C" int Combat_GetActionSummonedSpecies(int unused, int key, int *out) {
    short *entry = Combat_GetActionSummonedSpecies_SummonedSpeciesMappingRecords;
    int sentinel = -1;
    while (entry[0] != sentinel) {
        if (entry[0] == key) {
            out[0] = entry[1];
            out[1] = entry[2];
            return entry[3];
        }
        entry += 4;
    }
    return -1;
}
