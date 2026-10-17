#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
#pragma optimization_level 4
extern "C" unsigned char data_020fdcb0[];
extern "C" void func_0201fdd0(void *, void *, int, int, unsigned int, int, int, int, int, int, int, int);
// Original: arm9/main @ 0x0201FD38; symbol: func_0201fd38; size: 0x98.
extern "C" void GameState_InvokePartyMemberRecordLayout(void *param1, void *param2, int index) {
    GameState *state = GameState::GetInstance();
    if (state->GetPartyMemberByIndex(index) == 0) return;
    unsigned char *entry = data_020fdcb0 + index * 0x20;
    int value = *(int *)(entry + 4);
    if (value < 0) return;
    func_0201fdd0(param1, param2, index, value, *(unsigned int *)(entry + 0xc), 0x30, 0x1c, 7, 0x24, 0xb, 0xc, 1);
}
