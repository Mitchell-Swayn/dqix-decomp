#include <globaldefs.h>
ARM
extern "C" char *_ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" void *memcpy(void *, const void *, unsigned int);
struct State;
extern "C" void func_ov011_02184a24(State *, unsigned, unsigned);
extern "C" unsigned char data_ov004_02170444[];
// Original: arm9/ov004 @ 0x021633AC; symbol: func_ov004_021633ac; size: 0x38.
extern "C" void func_ov004_021633ac(unsigned arena, State *self) {
    char *copy = _ZN13SafeAllocator8AllocateEj(arena, 0x60);
    memcpy(copy, data_ov004_02170444, 0x60);
    func_ov011_02184a24(self, (unsigned)copy, 0x18);
}
