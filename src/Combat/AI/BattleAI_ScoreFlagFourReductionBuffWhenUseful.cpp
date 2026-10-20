#include <globaldefs.h>
ARM
namespace {
struct ActionDefinition {
    unsigned first, identity;
    unsigned mpCost:8, resultMode:2, remaining:22;
};
struct BattleAIState {
    char prefix[0x6e];
    unsigned char reductionUseful;
    char padding[0x64c - 0x6f];
    ActionDefinition* action;
};
} // namespace
extern "C" int BattleAI_SelectEnabledActionPolicyEntry(BattleAIState*, int);
extern "C" void BattleAI_ScorePartyStatusRemovalAndBuffTargets(BattleAIState*, int);
#pragma force_active on
// Original: arm9/ov024 @ 0x021FC320; symbol: func_ov024_021fc320; size: 0x48.
// Scores policy 23 when reduction is useful and action policy entry 11 is enabled.
extern "C" void BattleAI_ScoreFlagFourReductionBuffWhenUseful(BattleAIState* self)
{
    if (self->action->resultMode == 1 || !self->reductionUseful) return;
    if (!BattleAI_SelectEnabledActionPolicyEntry(self, 11)) return;
    BattleAI_ScorePartyStatusRemovalAndBuffTargets(self, 23);
}
#pragma force_active reset
