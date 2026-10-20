#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
extern "C" {
void Combat_RecountEligibleMonsterGroupMembers(void*);
int Combat_CollectEligiblePartyIds(void*, short*, int, int);
void* Combat_GetCommandActorSnapshot(void*, int);
void Combat_UpdateTimedStatusRecovery(unsigned char*, int, int);
void Combat_DecrementActiveFlagCounters(unsigned char*, int);
extern const short Combat_UpdateOutcomeAndRecoverStatusesAfterAction_CombatantSelectionInitialIds[];
}
struct GroupCount { unsigned char count:4; unsigned char other:4; };
#pragma always_inline on
struct SelectionIds { unsigned short values[8]; };
#pragma force_active on
// Original: arm9/ov000 @ 0x02157D3C; symbol: func_ov000_02157d3c; size: 0xe0.
// Updates battle outcome from party and monster availability, then advances participating actors status recovery.
extern "C" void Combat_UpdateOutcomeAndRecoverStatusesAfterAction(unsigned char* battle, unsigned char* command, int skipRecovery)
{
    Combat_RecountEligibleMonsterGroupMembers(battle);
    SelectionIds ids = *(const SelectionIds*)Combat_UpdateOutcomeAndRecoverStatusesAfterAction_CombatantSelectionInitialIds;
    if (Combat_CollectEligiblePartyIds(battle, (short*)ids.values, 8, 9) <= 0) {
        battle[0x8e14] = 2;
    } else if (((GroupCount*)(battle + 0x81b1))->count == 0) {
        battle[0x8e14] = 1;
    } else {
        battle[0x8e14] = 0;
    }
    if (((signed char*)battle)[0x8e14] == 0 && skipRecovery == 0) {
        for (int index = 0; index < command[8]; ++index) {
            unsigned char* snapshot = (unsigned char*)Combat_GetCommandActorSnapshot(command, index);
            if (snapshot) {
                Combat_UpdateTimedStatusRecovery(battle, *(short*)(snapshot + 0x20), (int)snapshot);
                Combat_DecrementActiveFlagCounters(battle, *(short*)(snapshot + 0x20));
            }
        }
    }
}

#pragma force_active off
