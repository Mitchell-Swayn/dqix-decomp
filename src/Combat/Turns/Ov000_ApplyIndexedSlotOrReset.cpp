#include <globaldefs.h>
extern "C" unsigned BattleMenu_ResetCurrentCommandAndFindPreviousCompletedParty(void*);
extern "C" void* BattleMenu_FindPartyCommandRecord(void*, unsigned);
extern "C" void InitializeObjectAndConfigureSelectionIfPresent(void*, unsigned);
extern "C" void GameState_ProcessEligibleListedMemberRecords(void*);
extern "C" void BattleMenu_ResetPanelsToFirstEligibleMember(void*);
// Original: arm9/ov000 @ 0x0217F78C; symbol: func_ov000_0217f78c; size: 0x48.
extern "C" ARM void Ov000_ApplyIndexedSlotOrReset(void* owner) {
    unsigned index = BattleMenu_ResetCurrentCommandAndFindPreviousCompletedParty(owner);
    void* record = BattleMenu_FindPartyCommandRecord(owner, index);
    if (record) {
        *(unsigned*)((char*)owner + 0x17c) = index;
        InitializeObjectAndConfigureSelectionIfPresent(record, 0);
        return;
    }
    GameState_ProcessEligibleListedMemberRecords(owner);
    BattleMenu_ResetPanelsToFirstEligibleMember(owner);
}
