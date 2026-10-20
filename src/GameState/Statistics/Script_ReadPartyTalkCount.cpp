#include <globaldefs.h>
ARM
extern "C" int GameState_CopyStatisticsRecord(void *);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov023 @ 0x021EA8B8; symbol: func_ov023_021ea8b8; size: 0x30.
extern "C" int Script_ReadPartyTalkCount(void *object) {
    unsigned char state[0xb0];
    GameState_CopyStatisticsRecord(state);
    unsigned int word = *(unsigned int *)(state + 0x20);
    Script_WriteIntegerReferenceOutput(object, (int)(word >> 16));
    return 1;
}
