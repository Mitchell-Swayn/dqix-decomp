#include <globaldefs.h>
ARM
extern "C" void LinkedQueue_InitializeNodeStatus(signed char *p);
// Original: arm9/ov017 @ 0x021C1ACC; symbol: func_ov017_021c1acc; size: 0x24.
extern "C" void Ov017_InitializeStateRecord(signed char *record) {
    LinkedQueue_InitializeNodeStatus(record);
    *((unsigned char *)record) = 0x37;
    *(unsigned int *)(record + 8) = 0;
    *(unsigned int *)(record + 0xc) = 0;
}
