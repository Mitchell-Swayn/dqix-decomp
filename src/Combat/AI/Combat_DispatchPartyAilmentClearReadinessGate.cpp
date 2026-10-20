#include <globaldefs.h>
ARM
extern "C" void Combat_CopyPartyIdsWhenTwoThirdsAilmentClearReady(int, int, int, int, int);
// Original: arm9/ov024 @ 0x021F090C; symbol: func_ov024_021f090c; size: 0x14.
extern "C" void Combat_DispatchPartyAilmentClearReadinessGate(int a, int b, int c, int d, int fifth) {
    Combat_CopyPartyIdsWhenTwoThirdsAilmentClearReady(a, b, c, d, fifth);
}
