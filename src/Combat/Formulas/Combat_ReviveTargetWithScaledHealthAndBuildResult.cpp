#include <globaldefs.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
ARM
#pragma always_inline on
namespace {
struct ActionDefinition { unsigned first; unsigned id:12, lowerMending:10, upperMending:10; char padding[0x20-8]; unsigned reserved20:20, appliedPartyMessage:10, rest20:2; unsigned appliedMonsterMessage:10, otherPartyMessage:10, otherMonsterMessage:10, rest24:2; };
struct ResultFlags { char prefix[0x1c]; unsigned char low:7, enabled:1; };
struct CombatActionState { char prefix[0xc]; ResultFlags* flags; unsigned char* combat; int appliedCount; };
struct RecoveryFlag { unsigned char selected:1, remaining:7; };
inline bool IsPartyIndex(int index) { bool party; if (index >= 0 && index <= 3) party = true; else party = false; return party; }
}
extern "C" bool GameObject_IsDead(int);
extern "C" void CombatantState_ReviveWithHealth(unsigned char*,int);
extern "C" GameObject* GameState_GetObjectWithFlag100(GameState*,int);
extern "C" unsigned short Combat_SelectMessageForPartyOrMonster(int,int,int);
extern "C" void Combat_SetResultMaskFlag(void*,unsigned long long*,unsigned);
extern "C" void* Combat_ClearCurrentResultNodeSlot(unsigned char*);
extern "C" void Combat_AppendResultMessage(void*,void*,unsigned short);
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void*,void*,void*,int,unsigned long long,unsigned char);
#pragma force_active on
// Original: arm9/ov024 @ 0x021DD278; symbol: func_ov024_021dd278; size: 0x2bc.
// Revives an enabled target with action- and mending-scaled health and builds the selected result feedback.
extern "C" void* Combat_ReviveTargetWithScaledHealthAndBuildResult(CombatActionState* self,int actorId,int targetId,ActionDefinition* action,int unused4,int unused5,unsigned char enabled)
{
    GameObject* actor = GetCombatantByID((int)self->combat, actorId);
    if (!actor) return 0;
    GameObject* target = GetCombatantByID((int)self->combat, targetId);
    if (!target) return 0;
    int dead = 0;
    if (GameObject_IsDead((int)target)) dead = 1;
    unsigned short actionId = (unsigned short)action->id;
    unsigned long long mask = 0;
    unsigned short message;
    if (enabled && dead) {
        float factor = 1.0f;
        switch (actionId) {
        case 0x27: factor = 0.5f; break;
        case 0x26:
        case 0x54:
            if (IsPartyIndex(actorId)) {
                unsigned short mending = (unsigned short)actor->currentStats_->primaryStats.magicalMending;
                if (mending <= action->lowerMending) factor = 0.25f;
                else if (mending >= action->upperMending) factor = 0.5f;
                else {
                    float slope = 25.0f / (float)(unsigned)(action->upperMending - action->lowerMending);
                    float steps = (float)(int)(slope * (float)(unsigned)(mending - action->lowerMending));
                    factor = (25.0f + steps) / 100.0f;
                }
            } else factor = 0.5f;
            break;
        }
        ModifiableCombatStats* stats = target->currentStats_;
        short health = (int)(factor * (float)(unsigned)stats->primaryStats.maxHP);
        CombatantState_ReviveWithHealth((unsigned char*)stats, health);
        Combat_SetResultMaskFlag(self->combat, &mask, 3);
        ((RecoveryFlag*)((unsigned char*)target->currentStats_ + 0x3b))->selected = 1;
        if (IsPartyIndex(targetId)) {
            GameObject* member = GameState_GetObjectWithFlag100(GameState::GetInstance(), targetId);
            if (member) ((unsigned char*)member->currentStats_)[0x3a] = 1;
        }
        message = Combat_SelectMessageForPartyOrMonster(targetId, action->appliedPartyMessage, action->appliedMonsterMessage);
        self->appliedCount++;
    } else if (dead) message = 0x21;
    else message = Combat_SelectMessageForPartyOrMonster(targetId, action->otherPartyMessage, action->otherMonsterMessage);
    void* result = Combat_ClearCurrentResultNodeSlot(self->combat);
    if (!result) return 0;
    Combat_AppendResultMessage(self->combat, result, message);
    Combat_PopulateResultWithCurrentHealthAndMagic(self->combat, result, target, 0, mask, self->flags->enabled != 0);
    return result;
}
#pragma force_active reset
