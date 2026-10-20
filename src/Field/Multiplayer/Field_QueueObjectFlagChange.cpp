#include <globaldefs.h>
ARM
extern "C" void *Network_GetCommandRecordPool(void);
extern "C" void Network_QueueOutgoingRecord(void *, const void *, short);
// Original: arm9/ov017 @ 0x021CEDF4; symbol: func_ov017_021cedf4; size: 0x40.
extern "C" void Field_QueueObjectFlagChange(void *source, const void *destination, int value) {
    void *target = Network_GetCommandRecordPool();
    unsigned char record[0x14];
    record[0] = 0x13;
    *(void **)(record + 4) = source;
    *(const void **)(record + 8) = destination;
    *(unsigned int *)(record + 0xc) = value;
    Network_QueueOutgoingRecord(target, record, 0);
}
