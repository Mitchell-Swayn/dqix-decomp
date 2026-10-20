#include <globaldefs.h>
ARM
extern "C" int Combat_CopyPartyIdsWhenTwoThirdsStatusBit5ClearReady(void *entry, unsigned int flags, unsigned int count, void *outCount, void *outEntries);
// Original: arm9/ov024 @ 0x021F0734; symbol: FilterCombatantsByRecordAndFieldFlags; size: 0x14.
// Checks descriptor and record flags, then applies a threshold to byte field 0x4A before returning the matched list.
extern "C" int Combat_DispatchPartyStatusBit5ClearReadinessGate(void *entry, unsigned int flags, unsigned int count, void *outCount, void *outEntries) {
    return Combat_CopyPartyIdsWhenTwoThirdsStatusBit5ClearReady(entry, flags, count, outCount, outEntries);
}
