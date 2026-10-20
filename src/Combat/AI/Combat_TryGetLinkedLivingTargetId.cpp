#include <globaldefs.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
ARM
struct BattleAIContext { void* combat; };
struct ActionDescriptor { unsigned first; unsigned id:12, other:20; };
extern "C" GameObject* Combat_FindIndexedMonsterObject(void*, int);
extern "C" int Combat_HasMonsterActivationCondition(GameObject*);
extern "C" bool GameObject_IsDead(GameObject*);
extern "C" int Combat_SelectAutomaticActionTargets(void*, int, unsigned short, short*);
// Original: arm9/ov024 @ 0x021EDF00; symbol: Combat_TryGetLinkedLivingTargetId; size: 0x6c.
// Returns the active linked target identifier only when the linked combatant exists and is alive.
extern "C" int Combat_TryGetLinkedLivingTargetId(BattleAIContext* self, int actor, short* output)
{
    GameObject* source = Combat_FindIndexedMonsterObject(self->combat, actor);
    if (!source) return 0;
    if (!Combat_HasMonsterActivationCondition(source)) return 0;
    GameObject* target = GetCombatantByID((int)self->combat, *(short*)((char*)source->currentStats_ + 0x2e));
    if (target && !GameObject_IsDead(target)) {
        output[0] = *(short*)((char*)source->currentStats_ + 0x2e);
        return 1;
    }
    return 0;
}
