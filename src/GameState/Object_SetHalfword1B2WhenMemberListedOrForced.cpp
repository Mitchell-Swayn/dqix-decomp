#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
#pragma optimization_level 4
extern "C" unsigned char *GameState_GetIndexList(void);
// Original: arm9/main @ 0x02053F7C; symbol: func_02053f7c; size: 0x68.
extern "C" void Object_SetHalfword1B2WhenMemberListedOrForced(void *record, short value, int force) {
    GameState::GetInstance();
    volatile unsigned char *state = GameState_GetIndexList();
    int found = 0;
    if (state != 0) {
        for (int i = 0; i < state[0xf7c]; ++i) {
            unsigned char id = state[0xf78 + i];
            short recordId = *(volatile short *)((char *)record + 4);
            if ((unsigned short)id == recordId) {
                found = 1;
                break;
            }
        }
    }
    if (force != 0 || found != 0)
        *(short *)((char *)record + 0x1b2) = value;
}
