#include <globaldefs.h>
ARM
extern "C" void *func_ov011_021849c8(void *);
extern "C" void *func_ov023_021f6880(void *, unsigned int);
extern "C" unsigned int OV023_ReadHalfwordField04(void *);
// Original: arm9/ov004 @ 0x02156FA0; symbol: func_ov004_02156fa0; size: 0x34.
extern "C" void *func_ov004_02156fa0(void *state, unsigned int key) {
    void *node = func_ov023_021f6880(func_ov011_021849c8(state), key);
    if (node != 0 && OV023_ReadHalfwordField04(node) == 1) return node;
    return 0;
}
