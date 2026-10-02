#pragma once
#include "Util/Random.h"

// Prefix used by the member-function callback table at 0x021ff1e0.
// The dispatcher at 0x021da55c passes actor/target indices, an action ID,
// an action record and the unadjusted damage. The remaining context is unknown.
struct DamageAdjustmentContext {
    Random* random;
};

struct DamageAdjustmentAction;
