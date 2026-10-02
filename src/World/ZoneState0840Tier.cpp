#include "World/Zone3DEmbeddedState.h"

// Tier thresholds are observed; their gameplay effect remains unresolved.
void ZoneState0840::UpdateEntryCountTier()
{
    if (unknown_1b3c == 6) return;
    unsigned int count = unknown_1b38;
    if (count < 7) unknown_1b41 = 1;
    else if (count >= 7 && count < 13) unknown_1b41 = 2;
    else if (count >= 13 && count < 19) unknown_1b41 = 3;
    else if (count >= 19 && count < 25) unknown_1b41 = 4;
    else if (count >= 25 && count < 30) unknown_1b41 = 5;
    else if (count >= 30) unknown_1b41 = 6;
    if (unknown_1b41 > unknown_1b3c) ++unknown_1b3c;
}

