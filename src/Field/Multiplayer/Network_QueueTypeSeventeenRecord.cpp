#include <globaldefs.h>
ARM
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(void*, const void*, short);
// Original: arm9/ov017 @ 0x021CE014; symbol: func_ov017_021ce014; size: 0x40.
extern "C" void Network_QueueTypeSeventeenRecord(void *unused, short first, short second, short third) {
    void *object = Network_GetCommandRecordPool();
    unsigned char record[0x14];
    record[0] = 0x11;
    *(short *)(record + 4) = first;
    *(short *)(record + 6) = second;
    *(short *)(record + 8) = third;
    Network_QueueOutgoingRecord(object, record, 0);
}
