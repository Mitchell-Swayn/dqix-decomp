#include <globaldefs.h>
ARM
extern "C" int Combat_CollectPresentEnemyIndices(void *, short *, int, int);
// Original: arm9/ov000 @ 0x02181D04; symbol: func_ov000_02181d04; size: 0x48.
extern "C" void CopyEnabledIdsToWords(void *source, int unused, int *destination) {
    short ids[12];
    int count = Combat_CollectPresentEnemyIndices(source, ids, 12, 0);
    for (int i = 0; i < count; ++i) destination[i] = ids[i];
}
