#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F68B8; symbol: func_ov023_021f68b8; size: 0x24.
extern "C" void Util_AdvanceLinkedPointer(void *object, int count) {
    void *node = *(void **)object;
    while (node && count > 0) {
        node = *(void **)((char *)node + 0x18);
        count--;
    }
}
