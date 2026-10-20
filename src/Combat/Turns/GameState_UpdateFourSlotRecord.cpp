#include <globaldefs.h>
ARM
extern "C" void* BattleMenu_GetEnemyTargetObjectId(void* object, int index);
extern "C" char* BattleMenu_FindPartyCommandRecord(char* p, int id);
// Original: arm9/ov000 @ 0x02162B90; symbol: func_ov000_02162b90; size: 0x84.
extern "C" void GameState_UpdateFourSlotRecord(char *self, int unused1, int value, int unused3, void *key, signed char slot, signed char flag) {
    unsigned bits = *(unsigned *)(self + 0x55f4);
    if (!(bits & 0x10000)) return;
    if (bits & 0x800000) return;
    int found = -1;
    for (int i = 0; i < 12; ++i) {
        if (key == BattleMenu_GetEnemyTargetObjectId(self + 0x3760, i)) {
            found = i;
            break;
        }
    }
    char *record = BattleMenu_FindPartyCommandRecord(self + 0x3760, slot);
    if (record) {
        *(short *)(record + 0x26) = value;
        *(signed char *)(record + 0x1d) = found;
        *(signed char *)(record + 0x2e) = flag;
    }
}
