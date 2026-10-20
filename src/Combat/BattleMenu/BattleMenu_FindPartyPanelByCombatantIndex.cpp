#include <globaldefs.h>
ARM
struct PartyPanel { unsigned char prefix[0x4c]; int combatantId; unsigned char remaining[0x3f8]; };
struct PartyPanelController { unsigned char prefix[0x958]; PartyPanel panels[4]; };
#pragma force_active on
// Original: arm9/ov025 @ 0x021DAFD0; symbol: func_ov025_021dafd0; size: 0x68.
// Finds the panel for a party combatant by its stored index in four 0x448-byte slots.
extern "C" char* BattleMenu_FindPartyPanelByCombatantIndex(void* object, int index)
{
    PartyPanelController* controller = (PartyPanelController*)object;
    int valid;
    if (index >= 0 && index <= 3) valid = 1;
    else valid = 0;
    if (valid) {
        for (int i = 0; i < 4; ++i) {
            if (controller->panels[i].combatantId == index) return (char*)&controller->panels[i];
        }
    }
    return 0;
}
#pragma force_active reset
