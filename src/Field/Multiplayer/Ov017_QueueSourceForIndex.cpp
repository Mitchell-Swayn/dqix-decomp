#include <globaldefs.h>
ARM
extern "C" void *Network_GetCommandRecordPool(void);
extern "C" void Network_QueueOutgoingRecord(void *object, const void *source, short value);
// Original: arm9/ov017 @ 0x021CC68C; symbol: func_ov017_021cc68c; size: 0x38.
extern "C" void Ov017_QueueSourceForIndex(unsigned char index) {
    void *object = Network_GetCommandRecordPool();
    unsigned char data[20];
    data[0] = 9;
    data[5] = index;
    data[4] = 1;
    Network_QueueOutgoingRecord(object, data, 0);
}
