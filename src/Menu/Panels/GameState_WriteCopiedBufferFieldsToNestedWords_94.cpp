#include <globaldefs.h>
ARM

extern "C" bool GameState_CopyStatisticsRecord(void *out);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);

// Original: arm9/ov023 @ 0x021EAB64; symbol: func_ov023_021eab64; size: 0x3C.
extern "C" bool GameState_WriteCopiedBufferFieldsToNestedWords_94(void *out) {
    unsigned char state[0xb0];
    GameState_CopyStatisticsRecord(state);
    volatile unsigned char *field = state + 0x94;
    Script_WriteIntegerReferenceOutput(out, *(unsigned short *)field);
    Script_WriteIntegerReferenceOutput((unsigned char *)out + 8, field[2]);
    return true;
}
