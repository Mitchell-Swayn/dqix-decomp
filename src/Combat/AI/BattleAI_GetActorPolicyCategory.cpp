#include <globaldefs.h>
ARM
// Original: arm9/ov024 @ 0x021FC498; symbol: func_ov024_021fc498; size: 0x14.
extern "C" unsigned int BattleAI_GetActorPolicyCategory(void *object) {
    unsigned char value = *((unsigned char *)*(unsigned int *)((unsigned char *)object + 0x138) + 0x3b);
    return ((unsigned int)value << 24) >> 28;
}
