#include "World/Zone3DEmbeddedState.h"

void ZoneState0840::Reset()
{
    unknown_1b34 = 0;
    unknown_1b38 = 0;
    unknown_1b3c = 1;
    unknown_1b40 = 1;
    unknown_1b41 = 1;
    unknown_1b42 = 0;
    unknown_1b44 = 0;
    unknown_1b48 = 0;
    unknown_1b4c = 0;
    unknown_1b50 = 0;
    unknown_1b54 = 0;
    unknown_1b60 = 1;
    unknown_1b61 = 0;
    unknown_1b62 = 0;
    unknown_1b64 = 0;
    unknown_1b58 = 0;
    unknown_1b5c = 0;
    Entry* entry = entries;
    for (int i = 0; i < 30; ++i, ++entry) entry->Reset();
    for (int i = 0; i < 3; ++i) unknown_1b68[i] = -1;
    unknown_1b74 = 0;
}
