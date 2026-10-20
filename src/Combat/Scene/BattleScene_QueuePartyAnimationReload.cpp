#include <globaldefs.h>
ARM
extern "C" void BattleScene_InitializePartyAnimationReloadRecord(void*);
// Original: arm9/ov000 @ 0x02168644; symbol: func_ov000_02168644; size: 0x38.
extern "C" void BattleScene_QueuePartyAnimationReload(unsigned char* self, unsigned char value) {
    unsigned char* counter = self + 0x77ee;
    unsigned char index = *counter;
    *counter = index + 1;
    unsigned char* base = self + 0x77d6;
    unsigned char* entry = base + index * 6;
    BattleScene_InitializePartyAnimationReloadRecord(entry);
    *entry = value;
}
