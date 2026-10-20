#include <globaldefs.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
ARM
namespace {
struct ActionDefinition {
    unsigned header;
    unsigned id:12, remaining:20;
};
struct CombatActionState {
    char prefix[0x10];
    int combat;
};
}
extern "C" int Combatant_HasFatalDamageProtection(unsigned char*);
// Original data: arm9/ov024 @ 0x021FE6E0; symbol: data_ov024_021fe6e0.
// Signed halfword action IDs 24, 25, 26, 27 followed by sentinel -1.
extern "C" short CombatCanFatalProtectionPreventLethalAction_UnknownRoleInitializedBytes[];
#pragma force_active on
// Original: arm9/ov024 @ 0x021EA78C; symbol: func_ov024_021ea78c; size: 0x70.
// Tests fatal-damage protection and membership in the sentinel-terminated lethal-action ID list.
extern "C" int Combat_CanFatalProtectionPreventLethalAction(CombatActionState* self, int targetId, ActionDefinition* action)
{
    GameObject* target = GetCombatantByID(self->combat, targetId);
    if (!target) return 0;
    if (!Combatant_HasFatalDamageProtection((unsigned char*)target)) return 0;
    for (int index = 0; CombatCanFatalProtectionPreventLethalAction_UnknownRoleInitializedBytes[index] != -1; ++index) {
        if (CombatCanFatalProtectionPreventLethalAction_UnknownRoleInitializedBytes[index] == action->id) return 1;
    }
    return 0;
}
#pragma force_active reset
