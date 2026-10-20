#include <globaldefs.h>
ARM

extern "C" void LinkedQueue_InitializeNodeStatus(signed char *p);

// Original: arm9/ov017 @ 0x021B46D8; symbol: func_ov017_021b46d8; size: 0x38.
extern "C" void ZoneEncounterLoader_InitializeCommand(unsigned char *record) {
    LinkedQueue_InitializeNodeStatus((signed char *)record);
    record[0] = 0x14;
    *(unsigned int *)(record + 8) = 0;
    record[0x10] = 0;
    *(unsigned int *)(record + 0xc) = 0xffffffff;
    *(unsigned short *)(record + 0x12) = 0;
    *(unsigned int *)(record + 0x14) = 0;
    record[0x11] = 0;
}
