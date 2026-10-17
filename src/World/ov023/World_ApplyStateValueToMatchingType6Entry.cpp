#include <globaldefs.h>
ARM
struct State;
extern "C" void* func_ov011_021849c8(State* self);
extern "C" void* func_ov023_021f6880(void** head, unsigned short value);
extern "C" unsigned OV023_ReadHalfwordField04(void* entry);
extern "C" void func_ov023_021f809c(void*, void*);
extern "C" void World_ApplyStateValueToMatchingType6Entry(State* state, unsigned short value);
// Original: arm9/ov023 @ 0x021F6680; symbol: func_ov023_021f6680; size: 0x3C.
extern "C" void World_ApplyStateValueToMatchingType6Entry(State* state, unsigned short value) {
    void** head = (void**)func_ov011_021849c8(state);
    void* entry = func_ov023_021f6880(head, value);
    if (!entry) return;
    if (OV023_ReadHalfwordField04(entry) != 6) return;
    func_ov023_021f809c(entry, state);
}
