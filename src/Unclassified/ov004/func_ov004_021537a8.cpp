#include <globaldefs.h>
ARM
extern "C" void *func_ov011_021849c8(void *);
extern "C" void *func_ov023_021f6880(void *, unsigned int);
// Original: arm9/ov004 @ 0x021537A8; symbol: func_ov004_021537a8; size: 0x34.
extern "C" void func_ov004_021537a8(void *state, unsigned int key, int value) {
    void *context = func_ov011_021849c8(state);
    void *node = func_ov023_021f6880(context, key);
    if (node == 0) return;
    void **vtable = *(void ***)node;
    ((void (*)(void *, int))vtable[0x3c / 4])(node, value);
}
