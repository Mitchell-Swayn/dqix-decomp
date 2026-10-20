#include <globaldefs.h>
ARM
extern "C" void BattleMenu_UpdateMemberRowPositions(void*);
// Original: arm9/ov000 @ 0x02180528; symbol: GameState_ResetFourSelectedRecordsAndOwnerState; size: 0x6C.
// Clears bit 2 in four indexed record flags, sets owner state fields, then calls the follow-up state handler.
extern "C" void GameState_ResetFourSelectedRecordsAndOwnerState(void* self) {
    for (int i = 0; i < 4; ++i) {
        signed char index = *((signed char*)self + 0x6C + i);
        char* record = (char*)self + 0x958 + index * 0x448;
        unsigned char flags = *(unsigned char*)(record + 0x24);
        *(unsigned char*)(record + 0x24) = flags & ~4u;
    }
    *(unsigned short*)((char*)self + 0x1D5E) = 0x10;
    *(unsigned*)((char*)self + 0x920) = 0x100;
    *(unsigned*)((char*)self + 0x92C) = 8;
    *(unsigned*)((char*)self + 0x924) = 0x100;
    *(unsigned*)((char*)self + 0x928) = 0x100;
    BattleMenu_UpdateMemberRowPositions(self);
}
