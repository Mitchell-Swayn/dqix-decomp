#include <globaldefs.h>
#include "GameState/GameState.h"
#include "DamageAdjustmentContext.h"

extern "C" {
ARM int func_ov024_021d8b68(DamageAdjustmentContext* context, int actor, int target,
                          unsigned short actionId, DamageAdjustmentAction* action, int damage) {
    GameObject* attacker = GameState::GetInstance()->GetCombatantByIndex(actor);
    if (!attacker)
        return damage;
    unsigned int attack = attacker->baseStats_->primaryStats.attack;
    float multiplier = NextRandomFloatBetween(context->random, 0.85f, 0.95f);
    return (int)((float)attack * multiplier);
}

ARM int func_ov024_021d8bc8(DamageAdjustmentContext* context, int actor, int target,
                          unsigned short actionId, DamageAdjustmentAction* action, int damage) {
    return (int)(2.5f * (float)damage);
}

ARM int func_ov024_021d8bec(DamageAdjustmentContext* context, int actor, int target,
                          unsigned short actionId, DamageAdjustmentAction* action, int damage) {
    return (int)(1.25f * (float)damage);
}
}
