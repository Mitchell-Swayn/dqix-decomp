#include <globaldefs.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
#include <Util/Random.h>
ARM
struct EffectContext { char unknown0[12]; unsigned char* flags; void* combat; };
struct StageDescriptor { unsigned first; unsigned id:12, otherId:20; char unknown8[0x32-8]; short delta; };
struct ChanceFlags { unsigned char unknown0[0x1c]; unsigned char low:7, bypass:1; };
extern "C" int CombatStatus_CanAdjustDefenseStage(ModifiableCombatStats*, unsigned char);
extern "C" int CombatStatus_AdjustDefenseStageAndRefreshTimer(ModifiableCombatStats*, int);
extern "C" int CombatStatus_CanAdjustAgilityStage(ModifiableCombatStats*, unsigned char);
extern "C" int CombatStatus_AdjustAgilityStageAndRefreshTimer(ModifiableCombatStats*, int);
extern "C" int CombatStatus_CanAdjustMagicalMightStage(ModifiableCombatStats*, unsigned char);
extern "C" int CombatStatus_AdjustMagicalMightStageAndRefreshTimer(ModifiableCombatStats*, int);
extern "C" int CombatStatus_CanAdjustMagicalMendingModifier(ModifiableCombatStats*, unsigned char);
extern "C" int CombatStatus_AdjustMagicalMendingModifierAndRefreshDuration(ModifiableCombatStats*, int);
extern "C" int CombatStatus_CanAdjustSpellResistanceStage(ModifiableCombatStats*, unsigned char);
extern "C" int CombatStatus_AdjustSpellResistanceStageAndRefreshDuration(ModifiableCombatStats*, int);
void UpdateCombatantDefense(int, int);
void UpdateCombatantAgility(int, int);
void UpdateCombatantMagicalMight(int, int);
void UpdateCombatantMagicalMending(int, int);
extern "C" int Combat_SelectStage2ActionId(void*, int, StageDescriptor*, unsigned char, signed char, int, int);
extern "C" int Combat_SelectAgilityStageChangeMessage(void*, int, StageDescriptor*, unsigned char, signed char, int, int);
extern "C" int Ov024_GetActionForMissingCombatant(void*, int, StageDescriptor*, unsigned char, signed char);
extern "C" void Combat_SetResultMaskFlag(void*, unsigned long long*, int);
extern "C" void* GameState_CreateAndAppendIndexedRecord(void*, int);
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void*, void*, GameObject*, int, unsigned long long, int);
extern "C" void* Combat_ClearCurrentResultNodeSlot(void*);
extern "C" void Combat_AppendResultMessage(void*, void*, unsigned short);
extern "C" void Combat_AppendTargetResultToCategoryList(void*, void*, int);
// Retains the original integer-to-float runtime call in the chance gate.
extern "C" float _ffltu(unsigned);
// Original: arm9/ov024 @ 0x021E3594; symbol: Combat_TryAdjustDefenseStageAndReturnEffectMask; size: 0x1a8.
// Clamps the signed stage delta, applies the attribute change, and emits the original result mask and message.
extern "C" unsigned long long Combat_TryAdjustDefenseStageAndReturnEffectMask(EffectContext* self, int unusedActor, int target, StageDescriptor* descriptor, int enabled)
{
    if (enabled <= 0) return 0;
    GameObject* object = GetCombatantByID((int)self->combat, target);
    if (!object) return 0;
    int roll = NextRandomMax((Random*)self->combat, 100);
    int delta = descriptor->delta;
    if (delta < -2) delta = -2;
    if (delta > 2) delta = 2;
    int lowering = 0;
    if (delta < 0) {
        if (descriptor->id != 0xad) {
        int chance = *((unsigned char*)object->currentStats_ + 0x50);
        if (!chance) return 0;
        if (!((ChanceFlags*)self->flags)->bypass) {
            _ffltu(chance);
            if (roll >= chance) return 0;
        }
        }
        lowering = 1;
    }
    int applied = 0;
    int stage = 0;
    if (CombatStatus_CanAdjustDefenseStage(object->currentStats_, lowering)) {
        stage = CombatStatus_AdjustDefenseStageAndRefreshTimer(object->currentStats_, (signed char)delta);
        UpdateCombatantDefense((int)self->combat, target);
        applied = 1;
    }
    unsigned long long mask = 0;
    if (applied) {
        int message = Combat_SelectStage2ActionId(self, target, descriptor, lowering, (signed char)stage, 1, 1);
        Combat_SetResultMaskFlag(self->combat, &mask, 30);
        void* record = GameState_CreateAndAppendIndexedRecord(self, message);
        if (record) Combat_PopulateResultWithCurrentHealthAndMagic(self->combat, record, object, 0, 0, 0);
    }
    return mask;
}
