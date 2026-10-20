#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyStatisticsRecord(void *out);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov023 @ 0x021EA1E0; symbol: func_ov023_021ea1e0; size: 0x34.
extern "C" int Grotto_CopyDetailedMapLevel(void *out) {
    unsigned char buffer[0xb0];
    GameState_CopyStatisticsRecord(buffer);
    unsigned int value = *(unsigned int *)(buffer + 0x7c);
    Script_WriteIntegerReferenceOutput(out, (unsigned int)(unsigned short)(value << 6) >> 6);
    return 1;
}
