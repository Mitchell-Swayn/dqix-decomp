#include <globaldefs.h>
ARM
struct State;
extern "C" void* func_ov011_021849c8(State*);
extern "C" void func_ov011_021849e0(State*, unsigned);
extern "C" void* func_ov023_021f6880(void**, unsigned);
extern "C" unsigned OV023_ReadHalfwordField04(void*);
extern "C" void func_ov023_021f9c0c(void*);
// Original: arm9/ov004 @ 0x0216B1C4; symbol: func_ov004_0216b1c4; size: 0x48.
extern "C" void GameState_UpdateIndexedNodeIfTypeSeven(State* state, int value) {
    void* list = func_ov011_021849c8(state);
    void* node = func_ov023_021f6880((void**)list, value);
    if (!node) return;
    if (OV023_ReadHalfwordField04(node) != 7) return;
    func_ov011_021849e0(state, (unsigned short)value);
    func_ov023_021f9c0c(node);
}
