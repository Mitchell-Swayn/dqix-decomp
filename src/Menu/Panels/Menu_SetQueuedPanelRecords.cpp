#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021EB564; symbol: func_ov023_021eb564; size: 0x14.
extern "C" void Menu_SetQueuedPanelRecords(void *p, unsigned int first, unsigned int second) {
    if (first && second) {
        *(unsigned int *)((unsigned char *)p + 0x20) = first;
        *(unsigned int *)((unsigned char *)p + 0x24) = second;
    }
}
