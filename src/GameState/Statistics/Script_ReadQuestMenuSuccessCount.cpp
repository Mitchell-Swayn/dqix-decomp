#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" bool GameState_CopyStatisticsRecord(void *);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov023 @ 0x021EA884; symbol: func_ov023_021ea884; size: 0x34.
extern "C" bool Script_ReadQuestMenuSuccessCount(void *param) {
    unsigned char output[0xB0];
    GameState_CopyStatisticsRecord(output);
    unsigned short value = *(unsigned int *)(output + 0x20);
    Script_WriteIntegerReferenceOutput(param, value);
    return true;
}
