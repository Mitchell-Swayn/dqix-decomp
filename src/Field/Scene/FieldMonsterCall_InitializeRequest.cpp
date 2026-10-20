#include <globaldefs.h>
ARM

extern "C" void LinkedQueue_InitializeNodeStatus(signed char *p);

// Original: arm9/ov017 @ 0x021C2744; symbol: func_ov017_021c2744; size: 0x40.
extern "C" void FieldMonsterCall_InitializeRequest(unsigned char *record) {
    LinkedQueue_InitializeNodeStatus((signed char *)record);
    record[0] = 0x45;
    record[0x10] = 0;
    *(unsigned short *)(record + 8) = 0x7d0;
    record[0x11] = 0;
    *(unsigned int *)(record + 0x14) = 0;
    *(unsigned int *)(record + 0x18) = 0xffffffff;
    *(unsigned short *)(record + 0x12) = 0;
    *(unsigned int *)(record + 0xc) = 0;
}
