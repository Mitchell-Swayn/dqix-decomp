#include <globaldefs.h>
ARM
extern "C" {
void* memset(void*, int, unsigned int);
int BattleMenu_HasCommandBlockingStatus(char*);
void BattleMenu_ResetPartyCommandSelection(char*);
void BattleMenu_OpenMemberCommandGrid(unsigned char*, int);
}
// Original: arm9/ov000 @ 0x02174614; symbol: func_ov000_02174614; size: 0x124.
// Resets and processes eligible mapped records for a negative selector, or
// processes the record whose stored key matches a nonnegative selector.
extern "C" void BattleMenu_ResetMemberCommandSelections(char* self, int selector) {
    char* record;
    if (selector < 0) {
        memset(self + 0x1d60, 0, 8);
        self[0x1d68] = 0;
        *(self + (signed char)self[0x1d68] + 0x1d60) = 1;
        int i = 0;
        for (; i < 4; ++i) {
            int slot = (signed char)(self + i)[0x6c];
            record = self + 0x958 + slot * 0x448;
            if (*(int*)(record + 0x4c) < 0) continue;
            if (!*(unsigned char*)(record + 0x87)) continue;
            if (BattleMenu_HasCommandBlockingStatus(record)) continue;
            BattleMenu_ResetPartyCommandSelection(record);
            if (!*(int*)(record + 0x38)) continue;
            BattleMenu_OpenMemberCommandGrid((unsigned char*)record, 0);
        }
        return;
    }
    for (int i = 0; i < 4; ++i) {
        int slot = (signed char)(self + i)[0x6c];
        record = self + 0x958 + slot * 0x448;
        if (selector != *(int*)(record + 0x4c)) continue;
        BattleMenu_ResetPartyCommandSelection(record);
        if (!*(int*)(record + 0x38)) return;
        BattleMenu_OpenMemberCommandGrid((unsigned char*)record, 0);
        return;
    }
}
