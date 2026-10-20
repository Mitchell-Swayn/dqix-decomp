#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
namespace {
struct ActionDefinition { unsigned header; unsigned id:12, lowerBound:10, upperBound:10; unsigned low08:14, damageId:8, rest08:10; unsigned word0c, flags10, word14; unsigned low18:16, scalingMode:2, rest18:14; };
struct DamageDefinition { unsigned low00:8, variation:10, rest00:14; unsigned low04:10, lower:10, upper:10, rest04:2; };
struct MagicStats { char prefix[0x10]; unsigned low10:10, mending:10, might:10, rest10:2; };
}
extern "C" void* ActionData_GetGlobalTables();
extern "C" int ActionData_FindDamageInPrimaryOrSecondaryTable(char*,unsigned);
#pragma force_active on
// Original: arm9/ov024 @ 0x021F8938; symbol: func_ov024_021f8938; size: 0x2a0.
// Computes an action's mean and lower magnitude estimates, interpolating magic
// stat scaling when selected, then clamps both estimates to0..32767.
extern "C" void BattleAI_ComputeActionBaseMagnitudeRange(void* unusedSelf,float* mean,float* minimum,int unused3,ActionDefinition* action,GameObject* actor)
{
    char* tables = (char*)ActionData_GetGlobalTables();
    *mean = 0;
    *minimum = 0;
    DamageDefinition* damage = (DamageDefinition*)ActionData_FindDamageInPrimaryOrSecondaryTable(tables, action->damageId);
    if (damage) {
        if (action->scalingMode == 2) {
            int lowerBound = action->lowerBound;
            int upperBound = action->upperBound;
            float lower;
            float upper;
            int scaled = 0;
            lower = (float)damage->lower;
            upper = (float)damage->upper;
            float stat;
            if (action->flags10 & 0x4000) {
                stat = (float)(unsigned)(unsigned short)((MagicStats*)actor->currentStats_)->mending;
                scaled = 1;
            } else if (action->flags10 & 0x8000) {
                stat = (float)(unsigned)(unsigned short)((MagicStats*)actor->currentStats_)->might;
                scaled = 1;
            } else stat = 0.5f * (lower + upper);
            if (scaled) {
                if (stat <= (float)lowerBound) *mean = lower;
                else if (stat >= (float)upperBound) *mean = upper;
                else {
                    float deltaStat = stat - (float)lowerBound;
                    float deltaDamage = upper - lower;
                    *mean = deltaStat * (deltaDamage / (float)(upperBound - lowerBound));
                    *mean += lower;
                }
                *minimum = *mean - (float)damage->variation;
            } else {
                *mean = 0.5f * (upper + lower);
                *minimum = lower;
            }
        } else {
            *mean = 0.5f * (float)(damage->lower + damage->upper);
            *minimum = (float)damage->lower;
        }
    } else {
        *mean = 0;
        *minimum = 0;
    }
    if (*mean < 0) *mean = 0;
    else if (*mean >= 32767.0f) *mean = 32767.0f;
    if (*minimum < 0) *minimum = 0;
    else if (*minimum >= 32767.0f) *minimum = 32767.0f;
}
#pragma force_active reset
