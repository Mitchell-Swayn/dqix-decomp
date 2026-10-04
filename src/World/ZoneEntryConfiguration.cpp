#include "World/Zone3DEmbeddedState.h"
#include "std_library_functions.h"

extern const unsigned short gZoneEntryConfigurationDefaults[10];

void ZoneState0840::Entry::Configuration1a::Reset()
{
    memcpy(values, gZoneEntryConfigurationDefaults, sizeof(values));
    flags14.low = 0;
    flags14.middle = 2;
    flags14.high = 0;
    flags15.low = 0;
    unknown18 = 0x1000;
    unknown1a = 0x1000;
    unknown16 = 0x36b7;
}
