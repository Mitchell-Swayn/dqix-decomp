#include <globaldefs.h>
ARM
// Original: arm9/ov000:0215fb9c; Returns true when sentinel lookup is positive or key equals 0xf2 or 0x1da.
extern "C" int Combat_GetActionSummonedSpecies(int, int, int*);
extern "C" int Combat_IsSummoningAction(int unused, int key) {
    int values[2];
    int result = Combat_GetActionSummonedSpecies(unused, key, values);
    if (result > 0) goto yes;
    if (key == 0xf2) goto yes;
    if (key == 0x1da) goto yes;
    goto no;
yes:
    return 1;
no:
    return 0;
}
