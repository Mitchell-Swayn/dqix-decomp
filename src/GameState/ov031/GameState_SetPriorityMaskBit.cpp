#include <globaldefs.h>
ARM
#pragma optimization_level 4

extern "C" void *SelectStateWordByPriorityMask(int mask);

// Original: arm9/ov031 @ 0x02214AC8; symbol: func_ov031_02214ac8; size: 0x34.
extern "C" void GameState_SetPriorityMaskBit(unsigned priority) {
    char *state = (char *)SelectStateWordByPriorityMask(0x10);
    if (priority > 13) priority = 13;
    unsigned short old = *(unsigned short *)(state + 0xd00 + 0x16);
    unsigned int bit = 1 << (priority - 1);
    *(unsigned short *)(state + 0xd00 + 0x16) = old | bit;
}
