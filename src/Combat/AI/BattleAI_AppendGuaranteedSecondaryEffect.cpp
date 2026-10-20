#include <globaldefs.h>
ARM
namespace {
struct ScoredEffect {
    float magnitude;
    unsigned char category, flags, targetId, probability, kind, reserved9;
};
struct ActionDefinition {
    char prefix[0x32];
    short secondaryMagnitude;
};
struct BattleAIState {
    char prefix[0x64c];
    ActionDefinition* action;
    char padding[8];
    unsigned char* effects;
    ScoredEffect effectTemplate;
};
} // namespace
extern "C" void AppendTenByteRecordIfCapacity(unsigned char*, const unsigned char*);
#pragma force_active on
// Original: arm9/ov024 @ 0x021FD160; symbol: func_ov024_021fd160; size: 0x5C.
// Copies the scoring template and appends a secondary effect with 100 percent probability.
extern "C" void BattleAI_AppendGuaranteedSecondaryEffect(BattleAIState* self, int category)
{
    ScoredEffect effect = self->effectTemplate;
    effect.magnitude = (float)self->action->secondaryMagnitude;
    effect.category = category;
    effect.probability = 100;
    effect.kind = 8;
    AppendTenByteRecordIfCapacity(self->effects, (const unsigned char*)&effect);
}
#pragma force_active reset
