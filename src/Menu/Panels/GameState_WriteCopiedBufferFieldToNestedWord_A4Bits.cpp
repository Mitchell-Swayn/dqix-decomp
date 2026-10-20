#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyStatisticsRecord(void *out);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov023 @ 0x021EAD74; symbol: func_ov023_021ead74; size: 0x34.
extern "C" bool GameState_WriteCopiedBufferFieldToNestedWord_A4Bits(void *arg) {
    unsigned char state[0xb0];
    GameState_CopyStatisticsRecord(state);
    Script_WriteIntegerReferenceOutput(arg, (*(unsigned int *)(state + 0xa4) << 10) >> 18);
    return true;
}
