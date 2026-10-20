#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyStatisticsRecord(void *out);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
struct Field { unsigned char pad[0x70]; unsigned value:16; unsigned rest:16; };
// Original: arm9/ov023 @ 0x021EA0B4; symbol: func_ov023_021ea0b4; size: 0x34.
extern "C" int GameState_WriteCopiedBufferFieldToNestedWord_70(void *out) {
    unsigned char state[0xB0];
    GameState_CopyStatisticsRecord(state);
    Script_WriteIntegerReferenceOutput(out, ((Field *)state)->value);
    return 1;
}
