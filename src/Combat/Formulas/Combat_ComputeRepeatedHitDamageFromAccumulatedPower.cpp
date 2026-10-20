#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
#include <Util/Random.h>
ARM
namespace {
struct CombatActionState { char prefix[0x10]; unsigned char* battle; };
}
struct RecordForFlag18;
extern "C" signed char Combat_GetCombatantLevel(void*, int);
extern "C" float Combat_GetDamageStatusMultiplier(unsigned);
extern "C" int Combatant_HasDamageRetaliationStatus(RecordForFlag18*);
extern "C" void* GameState_GetIndexList(GameState*);
extern "C" int PartyRoster_ContainsActiveObjectIndex(unsigned char*, unsigned);
extern "C" void Combat_IncrementCappedEventCounter(unsigned char*, int);
extern "C" int Combat_TestMonsterDescriptorMode(void*, int, int, int);
extern "C" int Combat_HasSuperHighTension(void*);
#pragma force_active on
// Original: arm9/ov024 @ 0x021E67C8; symbol: func_ov024_021e67c8; size: 0x180.
// Computes level-based repeated-hit damage, then applies target scaling, status multipliers and descriptor overrides.
extern "C" int Combat_ComputeRepeatedHitDamageFromAccumulatedPower(CombatActionState* self, int actorId, int targetId)
{
    unsigned char* battle = self->battle;
    int level = Combat_GetCombatantLevel(battle, actorId);
    float sample = NextRandomFloatBetween((Random*)battle, 0.8f, 1.0f);
    float damage = (float)(level + 5) * sample;
    if (damage > 100.0f) damage = 100.0f;
    GameObject* target = GetCombatantByID((int)self->battle, targetId);
    if (target) {
        damage *= (float)(unsigned)((unsigned char*)target->currentStats_)[0x40] / 100.0f;
    }
    if (target) {
        unsigned status = ((unsigned char*)target->currentStats_)[0x21];
        if (status <= 3) damage *= Combat_GetDamageStatusMultiplier((signed char)status);
        if (Combatant_HasDamageRetaliationStatus((RecordForFlag18*)target)) damage *= Combat_GetDamageStatusMultiplier(1);
        if (PartyRoster_ContainsActiveObjectIndex((unsigned char*)GameState_GetIndexList(GameState::GetInstance()), targetId) && target) {
            if (((unsigned char*)target->currentStats_)[0x21] == 1) Combat_IncrementCappedEventCounter(self->battle, 0);
        }
    }
    if (Combat_TestMonsterDescriptorMode(self->battle, targetId, 0, 1)) damage = (float)NextRandomMax((Random*)self->battle, 2);
    if (Combat_HasSuperHighTension(target)) damage = 0.5f * damage;
    return (int)damage;
}
#pragma force_active reset
