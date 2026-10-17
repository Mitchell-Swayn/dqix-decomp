#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void GameState_WriteUnknownF70(void*, unsigned);
extern "C" void func_ov011_021848a0(void*, unsigned);
extern "C" unsigned char data_ov004_02171034[];
// Original: arm9/ov004 @ 0x0216E8B4; symbol: func_ov004_0216e8b4; size: 0x3C.
extern "C" int GameState_SetFlagAndInitializeState3E7(void* self) {
    data_ov004_02171034[2] = 1;
    void* state = _ZN9GameState11GetInstanceEv();
    GameState_WriteUnknownF70(state, 0);
    func_ov011_021848a0(self, 0x3e7);
    return 0;
}
