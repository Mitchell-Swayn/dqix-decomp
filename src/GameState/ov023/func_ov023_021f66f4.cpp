#include <globaldefs.h>
ARM
struct State;
extern "C" void *func_ov011_021849c8(State *);
extern "C" void *func_ov023_021f6880(void *, unsigned);
// Original: arm9/ov023 @ 0x021F66F4; symbol: func_ov023_021f66f4; size: 0x34.
extern "C" void func_ov023_021f66f4(void *self, unsigned id, unsigned value) {
    void *context = func_ov011_021849c8((State *)self);
    void *object = func_ov023_021f6880(context, id);
    if (object == 0) return;
    void **vtable = *(void ***)object;
    ((void (*)(void *, unsigned))vtable[0xf4 / 4])(object, value);
}
