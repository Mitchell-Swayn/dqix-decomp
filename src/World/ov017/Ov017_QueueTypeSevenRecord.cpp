#include <globaldefs.h>
ARM
extern "C" void *ReadGlobalAt02100044(void);
extern "C" void MoveQueuedRecordAndApplySourceValue(void *, const void *, short);
// Original: arm9/ov017 @ 0x021CC340; symbol: func_ov017_021cc340; size: 0x48.
extern "C" void Ov017_QueueTypeSevenRecord(unsigned char a, unsigned char b, unsigned char c) {
    void *object = ReadGlobalAt02100044();
    unsigned char record[20];
    record[0] = 7;
    record[6] = a;
    record[9] = b;
    record[5] = 1;
    record[4] = c;
    MoveQueuedRecordAndApplySourceValue(object, record, 0);
}
