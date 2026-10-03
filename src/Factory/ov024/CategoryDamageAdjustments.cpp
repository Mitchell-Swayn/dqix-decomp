#include <globaldefs.h>
#include "GameState/GameState.h"
#include "DamageAdjustmentContext.h"

extern "C" int func_ov000_02156068(Random*, short, int, int);

// Observed views only: these offsets are read by the damage callback.
struct DamageAdjustmentStateView {
    char unknown[0x8e54];
    short damage;
};
struct DamageAdjustmentStatsView {
    char unknown[0x18];
    unsigned int flags;
};

extern "C" {
ARM int func_ov024_021d8c10(DamageAdjustmentContext* context, int actor, int target,
                          unsigned short actionId, DamageAdjustmentAction* action, int damage) {
    GameObject* attacker = GameState::GetInstance()->GetCombatantByIndex(actor);
    if (!attacker)
        return damage;
    if (((DamageAdjustmentStatsView*)attacker->currentStats_)->flags & 0x200)
        return ((DamageAdjustmentStateView*)context->random)->damage;
    return (int)(1.5f * (float)((DamageAdjustmentStateView*)context->random)->damage);
}
ARM int func_ov024_021d8c70(DamageAdjustmentContext* context, int actor, int target,
                          unsigned short actionId, DamageAdjustmentAction* action, int damage) {
    return (int)(0.75f * (float)damage);
}
ARM int func_ov024_021d8c90(DamageAdjustmentContext* context, int actor, int target,
                          unsigned short actionId, DamageAdjustmentAction* action, int damage) {
    if (!func_ov000_02156068(context->random, (short)target, 1, 0))
        return damage;
    return (int)(1.5f * (float)damage);
}
ARM int func_ov024_021d8cd4(DamageAdjustmentContext* context, int actor, int target,
                          unsigned short actionId, DamageAdjustmentAction* action, int damage) {
    return (int)(0.5f * (float)damage);
}
ARM int func_ov024_021d8cf4(DamageAdjustmentContext* context, int actor, int target,
                          unsigned short actionId, DamageAdjustmentAction* action, int damage) {
    if (!func_ov000_02156068(context->random, (short)target, 3, 0))
        return damage;
    return (int)(1.5f * (float)damage);
}
}