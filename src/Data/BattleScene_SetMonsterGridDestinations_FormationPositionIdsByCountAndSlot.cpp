// Original data: arm9/ov000 @ 0x2183118; symbol: data_ov000_02183118.
// Formation position IDs indexed by combatant count minus1 and slot. Consumer02167cd4 uses eight-byte rows.
// Observed values: hex 160000000000000015170000000000001d16200000000000140c0d18000000001c0b160e21000000140b0c0d0e180000140b0c160d0e1800130a0b0c0d0e0f19.
// Span: 64 bytes to next configured symbol; logical object size may differ.
#include <globaldefs.h>
// Formation position IDs indexed by combatant count minus1 and slot. Consumer02167cd4 uses eight-byte rows.
extern "C" {
extern const unsigned char BattleScene_SetMonsterGridDestinations_FormationPositionIdsByCountAndSlot[8][8] = {
    {22, 0, 0, 0, 0, 0, 0, 0},
    {21, 23, 0, 0, 0, 0, 0, 0},
    {29, 22, 32, 0, 0, 0, 0, 0},
    {20, 12, 13, 24, 0, 0, 0, 0},
    {28, 11, 22, 14, 33, 0, 0, 0},
    {20, 11, 12, 13, 14, 24, 0, 0},
    {20, 11, 12, 22, 13, 14, 24, 0},
    {19, 10, 11, 12, 13, 14, 15, 25},
};
}
