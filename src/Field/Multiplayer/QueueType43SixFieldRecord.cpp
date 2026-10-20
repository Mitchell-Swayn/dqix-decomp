#include <globaldefs.h>
ARM

extern "C" void *Network_GetCommandRecordPool();
extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" void Network_QueueOutgoingRecord(void *object, const void *source, short value);

// Original: arm9/ov017 @ 0x021C6A9C; symbol: func_ov017_021c6a9c; size: 0x68.
extern "C" void QueueType43SixFieldRecord(int first, int second, int third, int fourth, unsigned char fifth, signed char sixth) {
    unsigned char record[0x14];
    void *object = Network_GetCommandRecordPool();
    unsigned char *payload = record + 4;
    _ZN9GameState11GetInstanceEv();
    record[0] = 0x43;
    *(unsigned short *)(payload) = (unsigned short)first;
    *(unsigned short *)(payload + 2) = (unsigned short)third;
    payload[4] = (unsigned char)fourth;
    payload[5] = fifth;
    payload[6] = (unsigned char)second;
    payload[7] = sixth;
    Network_QueueOutgoingRecord(object, record, 0);
}
