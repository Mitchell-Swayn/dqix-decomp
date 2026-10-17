#include <globaldefs.h>
extern "C" unsigned func_ov000_0217f7d4(void*);
extern "C" void* FindFourSlotRecordByIndex(void*, unsigned);
extern "C" void InitializeObjectAndConfigureSelectionIfPresent(void*, unsigned);
extern "C" void GameState_ProcessEligibleListedMemberRecords(void*);
extern "C" void func_ov000_02174c14(void*);
// Original: arm9/ov000 @ 0x0217F78C; symbol: func_ov000_0217f78c; size: 0x48.
extern "C" ARM void Ov000_ApplyIndexedSlotOrReset(void* owner) {
    unsigned index = func_ov000_0217f7d4(owner);
    void* record = FindFourSlotRecordByIndex(owner, index);
    if (record) {
        *(unsigned*)((char*)owner + 0x17c) = index;
        InitializeObjectAndConfigureSelectionIfPresent(record, 0);
        return;
    }
    GameState_ProcessEligibleListedMemberRecords(owner);
    func_ov000_02174c14(owner);
}
