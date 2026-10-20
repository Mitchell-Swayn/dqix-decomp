#include <globaldefs.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
ARM
struct BattleAIContext { void* combat; };
struct ActionDescriptor { unsigned first; unsigned id:12, other:20; };
extern "C" GameObject* Combat_FindIndexedMonsterObject(void*, int);
extern "C" int Combat_HasMonsterActivationCondition(GameObject*);
extern "C" bool GameObject_IsDead(GameObject*);
extern "C" int Combat_SelectAutomaticActionTargets(void*, int, unsigned short, short*);
// Original: arm9/ov024 @ 0x021EDF6C; symbol: Combat_CollectTargetsForPackedActionId; size: 0x34.
// Collects automatic targets using the low twelve-bit action identifier.
extern "C" int Combat_CollectTargetsForPackedActionId(BattleAIContext* self, int actor, ActionDescriptor* action, int* count, short* output)
{
    *count = Combat_SelectAutomaticActionTargets(self->combat, actor, (unsigned short)action->id, output);
    return 1;
}
