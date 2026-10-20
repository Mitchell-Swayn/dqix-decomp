#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyStatisticsRecord(void *out);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
struct Field { unsigned char pad[0x38]; unsigned value:24; unsigned rest:8; };
// Original: arm9/ov023 @ 0x021E9D60; symbol: func_ov023_021e9d60; size: 0x34.
extern "C" int GameState_WriteCopiedBufferFieldToNestedWord_38(void *out) {
    unsigned char state[0xB0];
    GameState_CopyStatisticsRecord(state);
    Script_WriteIntegerReferenceOutput(out, ((Field *)state)->value);
    return 1;
}
