#include "World/Zone3DEmbeddedState.h"
#include "System/Memory.h"
#include "std_library_functions.h"

void ZoneState0840::Entry::Reset()
{
    memset(unknown_0, 0, sizeof(unknown_0));
    flags.low = 0;
    flags.kind = 0;
    byteFlags.low = 0;
    flags.unknown15 = 0;
    flags.unknown19 = 0;
    flags.state = 0;
    flags.unknown30 = 0;
    value.low = 0;
    flags.unknown31 = 0;
    byteFlags.high = 0;
    value.value = 0;
    VectorizedMemset(identifier, 0, sizeof(identifier));
    parameters6c.unknown0 = 2000;
    parameters6c.unknown12 = 1;
    parameters6c.unknown16 = 1;
    parameters6c.unknown28 = 0;
    parameters6c.unknown21 = 0;
    parameters6c.unknown27 = 0;
    parameters6c.unknown25 = 0;
    parameters6c.unknown26 = 0;
    parameters6c.unknown29 = 0;
    parameters6c.unknown30 = 1;
    parameters6c.unknown31 = 0;
    parameters70.unknown0 = 511;
    parameters70.unknown30 = 0;
    parameters70.unknown9 = 300;
    parameters70.unknown19 = 706;
    unknown_74 = 0;
    configuration1a.Reset();
    VectorizedMemset(&unknown_38, 0, sizeof(unknown_38));
    VectorizedMemset(unknown_50, 0, sizeof(unknown_50));
}

