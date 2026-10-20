#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x02169B54; symbol: func_ov000_02169b54; size: 0x24.
extern "C" void *CombatScript_FindCommandByOpcode(void *node, unsigned int key) {
    while (node != 0) {
        if (*(unsigned int *)node == key)
            return node;
        node = *(void **)((unsigned char *)node + 4);
    }
    return 0;
}
