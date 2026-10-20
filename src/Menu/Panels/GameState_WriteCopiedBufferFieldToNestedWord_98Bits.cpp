#include <globaldefs.h>
ARM

extern "C" bool GameState_CopyStatisticsRecord(void *out);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);

// Original: arm9/ov023 @ 0x021EABD4; symbol: func_ov023_021eabd4; size: 0x34.
extern "C" int GameState_WriteCopiedBufferFieldToNestedWord_98Bits(void *arg) {
    unsigned char buffer[0xb0];
    GameState_CopyStatisticsRecord(buffer);
    unsigned int value = *(unsigned int *)(buffer + 0x98);
    value <<= 8;
    value >>= 25;
    Script_WriteIntegerReferenceOutput(arg, value);
    return 1;
}
