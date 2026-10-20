#include <globaldefs.h>
ARM
struct RosterBytes { unsigned char values[8]; };
struct RosterRecord { unsigned short species; RosterBytes first; unsigned char byte0A, byte0B, byte0C; RosterBytes second; unsigned char byte15, byte16, byte17; };
#pragma force_active on
// Original: arm9/ov000 @ 0x02165F90; symbol: func_ov000_02165f90; size: 0x78.
// Copies every roster field, preserving the two eight-byte byte sequences.
extern "C" RosterRecord* MonsterGroup_CopyRosterRecord(RosterRecord* destination, const RosterRecord* source)
{
    destination->species = source->species;
    destination->first = source->first;
    destination->byte0A = source->byte0A;
    destination->byte0B = source->byte0B;
    destination->byte0C = source->byte0C;
    destination->second = source->second;
    destination->byte15 = source->byte15;
    destination->byte16 = source->byte16;
    destination->byte17 = source->byte17;
    return destination;
}
#pragma force_active off
