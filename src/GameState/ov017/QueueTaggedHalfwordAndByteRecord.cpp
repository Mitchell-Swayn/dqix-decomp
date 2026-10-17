#include <globaldefs.h>
ARM
extern "C" void *ReadGlobalAt02100044(void);
extern "C" void MoveQueuedRecordAndApplySourceValue(void *, const void *, short);
// Original: arm9/ov017 @ 0x021CFD5C; symbol: func_ov017_021cfd5c; size: 0x44.
extern "C" void QueueTaggedHalfwordAndByteRecord(unsigned char flag, short first, short second) {
    void *object = ReadGlobalAt02100044();
    unsigned char record[0x14];
    record[0] = 0xa4;
    unsigned char *body = record + 4;
    body[4] = flag;
    *(short *)body = first;
    *(short *)(body + 2) = second;
    MoveQueuedRecordAndApplySourceValue(object, record, 0);
}
