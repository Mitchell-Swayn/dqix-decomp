#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
extern "C" {
void Combat_ResetRecordPools(unsigned char*);
unsigned Resource_CountRangeAfterPrefix(void*, unsigned short*, unsigned, unsigned);
void CombatantState_ClearCoverLinks(char*);
// Original data: arm9/ov000 @ 0x02182D14; symbol: Combat_ResetTurnRecordsAndCombatantLinks_CombatantSelectionInitialIds.
// Sixteen signed halfword selection sentinels.
extern const short Combat_ResetTurnRecordsAndCombatantLinks_CombatantSelectionInitialIds[];
}
struct GroupResetProjection { unsigned char padding[0x81bf]; unsigned char flag; };
struct CombatTurnSelectionIds { unsigned short ids[16]; };
#pragma force_active on
// Original: arm9/ov000 @ 0x0215D588; symbol: func_ov000_0215d588; size: 0xb4.
// Resets turn pools and group state, then clears cover links for each collected combatant.
extern "C" void Combat_ResetTurnRecordsAndCombatantLinks(unsigned char* battle)
{
    Combat_ResetRecordPools(battle);
    for (int group = 0; group < 3; ++group) ((GroupResetProjection*)(battle + group * 24))->flag = 0;
    CombatTurnSelectionIds selection = *(const CombatTurnSelectionIds*)Combat_ResetTurnRecordsAndCombatantLinks_CombatantSelectionInitialIds;
    int count = Resource_CountRangeAfterPrefix(battle, selection.ids, 16, 0);
    for (int index = 0; index < count; ++index) {
        short id = (short)selection.ids[index];
        GameState* state = GameState::GetInstance();
        GameObject* actor = state->GetCombatantByIndex(id);
        if (actor) CombatantState_ClearCoverLinks((char*)actor->currentStats_);
    }
}
#pragma force_active off
