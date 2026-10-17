#include <globaldefs.h>
ARM

extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" void *ReadGlobalAt02100044();
extern "C" void MoveQueuedRecordAndApplySourceValue(void *object, const void *source, short value);

// Original: arm9/ov017 @ 0x021CC198; symbol: func_ov017_021cc198; size: 0x40.
extern "C" void QueueType2CRecordAndApplySourceValue(unsigned char objectByte, unsigned int objectWord) {
    _ZN9GameState11GetInstanceEv();
    void *object = ReadGlobalAt02100044();
    unsigned char record[0x14];
    unsigned char *payload = record + 4;
    record[0] = 0x2c;
    payload[0] = objectByte;
    *(unsigned int *)(payload + 4) = objectWord;
    MoveQueuedRecordAndApplySourceValue(object, record, 0);
}
