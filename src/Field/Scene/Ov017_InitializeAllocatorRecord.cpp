#include <globaldefs.h>
ARM
extern "C" void LinkedQueue_InitializeNodeStatus(signed char *);
extern "C" void InitializeObjectAllocatorAndOwnerFields(char *);
// Original: arm9/ov017 @ 0x021B61E4; symbol: func_ov017_021b61e4; size: 0x38.
extern "C" void Ov017_InitializeAllocatorRecord(char *record) {
    LinkedQueue_InitializeNodeStatus((signed char *)record);
    record[0] = 0x16;
    InitializeObjectAllocatorAndOwnerFields(record + 0x0c);
    record[0xfc] = 0;
    *(unsigned short *)(record + 0xfe) = 0;
    *(unsigned short *)(record + 0x100) = 0;
    record[0xfd] = 0;
}
