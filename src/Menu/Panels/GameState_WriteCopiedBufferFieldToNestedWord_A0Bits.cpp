#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyStatisticsRecord(void *out);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov023 @ 0x021EAD40; symbol: func_ov023_021ead40; size: 0x34.
extern "C" int GameState_WriteCopiedBufferFieldToNestedWord_A0Bits(void *out) {
    unsigned char state[0xb0];
    GameState_CopyStatisticsRecord(state);
    Script_WriteIntegerReferenceOutput(out, ((*(unsigned int *)(state + 0xa0)) << 9) >> 18);
    return 1;
}
