#include <globaldefs.h>
ARM
struct RankedActionChoice {
    short actionId;
    signed char targetId;
    unsigned char flags;
    float weight;
    unsigned reserved;
};
extern "C" void BattleAI_SetActionChoiceIdentity(RankedActionChoice*, int, int, int);
#pragma force_active on
// Original: arm9/ov024 @ 0x021F68C8; symbol: func_ov024_021f68c8; size: 0x54.
// Clears four ranked choices and gives each an invalid target and a weight of minus one.
extern "C" void BattleAI_InitializeRankedActionChoices(RankedActionChoice* choices)
{
    for (int index = 0; index < 4; ++index) {
        BattleAI_SetActionChoiceIdentity(&choices[index], 0, -1, 0);
        choices[index].weight = -1.0f;
    }
}
#pragma force_active reset
