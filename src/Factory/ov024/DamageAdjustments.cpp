#include <globaldefs.h>
#include "DamageAdjustmentContext.h"

extern "C" int func_ov000_02156068(Random*, short objectIndex, int category, int flagSelector);

extern "C" {
ARM int func_ov024_021d8a40(DamageAdjustmentContext* context, int actor, int target,
                          unsigned short actionId, DamageAdjustmentAction* action, int damage) {
    if (!func_ov000_02156068(context->random, (short)target, 2, 0))
        return damage;
    return (int)(1.5f * (float)damage);
}

ARM int func_ov024_021d8a84(DamageAdjustmentContext* context, int actor, int target,
                          unsigned short actionId, DamageAdjustmentAction* action, int damage) {
    if (func_ov000_02156068(context->random, (short)target, 0, 1))
        return damage + 1;
    return damage;
}

ARM int func_ov024_021d8ab4(DamageAdjustmentContext* context, int actor, int target,
                          unsigned short actionId, DamageAdjustmentAction* action, int damage) {
    return (int)(1.25f * (float)damage);
}

}
