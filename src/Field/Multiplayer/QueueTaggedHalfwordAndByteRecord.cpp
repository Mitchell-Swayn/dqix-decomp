#include <globaldefs.h>
ARM
extern "C" void *Network_GetCommandRecordPool(void);
extern "C" void Network_QueueOutgoingRecord(void *, const void *, short);
// Original: arm9/ov017 @ 0x021CFD5C; symbol: func_ov017_021cfd5c; size: 0x44.
extern "C" void QueueTaggedHalfwordAndByteRecord(unsigned char flag, short first, short second) {
    void *object = Network_GetCommandRecordPool();
    unsigned char record[0x14];
    record[0] = 0xa4;
    unsigned char *body = record + 4;
    body[4] = flag;
    *(short *)body = first;
    *(short *)(body + 2) = second;
    Network_QueueOutgoingRecord(object, record, 0);
}
