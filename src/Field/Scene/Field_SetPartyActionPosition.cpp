#include <globaldefs.h>
#pragma force_active on
ARM
struct PartyActionPosition { int x, y, z; };
// Original: arm9/ov017 @ 0x0218F574; symbol: func_ov017_0218f574; size: 0x8.
// Stores the three coordinate words supplied by the caller.
extern "C" void Field_SetPartyActionPosition(PartyActionPosition* position, int x, int y, int z)
{
    position->x = x;
    position->y = y;
    position->z = z;
}
