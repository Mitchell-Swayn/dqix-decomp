#include <globaldefs.h>
ARM

extern "C" void LinkedQueue_InitializeNodeStatus(signed char *p);

// Original: arm9/ov017 @ 0x021A7ADC; symbol: func_ov017_021a7adc; size: 0x5C.
extern "C" void Field_InitializeDeferredActorRequest(unsigned char *record) {
    LinkedQueue_InitializeNodeStatus((signed char *)record);
    record[0] = 0x40;
    *(unsigned int *)(record + 8) = 0;
    record[0xc] = 1;
    record[0xd] = 0;
    *(unsigned short *)(record + 0xe) = 0;
    *(unsigned short *)(record + 0x10) = 0;
    int invalid = 1 - 2;
    *(unsigned int *)(record + 0x14) = invalid;
    record[0x18] = 0;
    record[0x19] = 0;
    record[0x1a] = 0;
    *(short *)(record + 0x1c) = invalid;
    record[0x1b] = 0;
    *(unsigned int *)(record + 0x20) = 0;
    record[0x1e] = 2;
}
