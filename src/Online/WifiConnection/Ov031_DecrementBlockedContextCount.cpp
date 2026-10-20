#include <globaldefs.h>
ARM
extern "C" void OS_IrqHandler(void);
extern "C" void _Z15UnblockContextsP18BlockedContextList(void *);
// Original: arm9/ov031 @ 0x0220F330; symbol: func_ov031_0220f330; size: 0x38.
extern "C" void Ov031_DecrementBlockedContextCount(char *list) {
    if (*(void **)(list + 8) != (void *)OS_IrqHandler) return;
    unsigned int count = --*(unsigned int *)(list + 0x0c);
    if (count == 0) {
        *(unsigned int *)(list + 8) = 0;
        _Z15UnblockContextsP18BlockedContextList(list);
    }
}
