// Original data: arm9/ov000 @ 0x2182e24; symbol: data_ov000_02182e24.
// Combat action parameter triples (action ID, byte at combatant0x21, mode nibble); signed -1 sentinel. Consumer02153a18 walks6-byte entries.
// Observed values: hex 030001000100860001000100870002000100ed00030001006000040006008a0005000100920006000100a10306000100b90007000000b60008000000490109000000ffffffff0000.
// Span: 72 bytes to next configured symbol; logical object size may differ.
#include <globaldefs.h>
// Combat action parameter triples (action ID, byte at combatant0x21, mode nibble); signed -1 sentinel. Consumer02153a18 walks6-byte entries.
extern "C" {
extern const signed short Combat_ChargeActionMpAndPrepareActorState_ActionParameterTriples[12][3] = {
    {3, 1, 1},
    {134, 1, 1},
    {135, 2, 1},
    {237, 3, 1},
    {96, 4, 6},
    {138, 5, 1},
    {146, 6, 1},
    {929, 6, 1},
    {185, 7, 0},
    {182, 8, 0},
    {329, 9, 0},
    {-1, -1, 0},
};
}
