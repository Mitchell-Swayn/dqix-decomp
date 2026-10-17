#include <globaldefs.h>
ARM
extern "C" void *func_ov011_021849c8(void *);
extern "C" void *func_ov023_021f6880(void *, unsigned);
// Original: arm9/ov023 @ 0x021F66BC; symbol: func_ov023_021f66bc; size: 0x34.
extern "C" void InvokeEntryHandlerForStateKey(void *self, unsigned key, unsigned value) {
    void *state = func_ov011_021849c8(self);
    void *entry = func_ov023_021f6880(state, key);
    if (entry != 0) {
        void **vtable = *(void ***)entry;
        void (*handler)(void *, unsigned) = *(void (**)(void *, unsigned))((unsigned char *)vtable + 0xf0);
        handler(entry, value);
    }
}
