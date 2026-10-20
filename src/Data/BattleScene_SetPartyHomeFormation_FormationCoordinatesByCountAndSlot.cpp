// Original data: arm9/ov000 @ 0x2183158; symbol: data_ov000_02183158.
// Combat formation coordinate parameter indexed by party count minus1 and slot. Consumer021675a0 uses sixteen-byte rows and loads four-byte values.
// Observed values: hex 3d3200000000000000000000000000005c3300001e3100000000000000000000703500003d3200000a2f000000000000703500005c3300001e3100000a2f0000.
// Span: 64 bytes to next configured symbol; logical object size may differ.
#include <globaldefs.h>
// Combat formation coordinate parameter indexed by party count minus1 and slot. Consumer021675a0 uses sixteen-byte rows and loads four-byte values.
extern "C" {
extern const signed int BattleScene_SetPartyHomeFormation_FormationCoordinatesByCountAndSlot[4][4] = {
    {12861, 0, 0, 0},
    {13148, 12574, 0, 0},
    {13680, 12861, 12042, 0},
    {13680, 13148, 12574, 12042},
};
}
