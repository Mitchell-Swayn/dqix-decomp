#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021D4BC8; symbol: func_ov017_021d4bc8; size: 0x3C.
extern "C" void Ov017_InvokeIndexedCallback(void *callbacks, char *record, int value) {
    int index = *(int *)(record + 4);
    if (index < 0) return;
    if (index >= *(int *)((char *)callbacks + 4)) return;
    void **table = *(void ***)((char *)callbacks + 8);
    void (*callback)(void *, int) = (void (*)(void *, int))table[index];
    if (callback != 0) callback(record + 8, value - 1);
}
