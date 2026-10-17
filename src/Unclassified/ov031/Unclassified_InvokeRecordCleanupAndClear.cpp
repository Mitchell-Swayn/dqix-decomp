#include <globaldefs.h>
ARM
extern unsigned char data_ov031_02249f00[];
extern "C" void VectorizedMemset(void *dst, int value, unsigned int length);
typedef void (*CleanupCallback)(void *, unsigned, unsigned);
// Original: arm9/ov031 @ 0x022187FC; symbol: func_ov031_022187fc; size: 0x40.
extern "C" void Unclassified_InvokeRecordCleanupAndClear(void *self, unsigned *record) {
    unsigned value = *record;
    CleanupCallback callback = *(CleanupCallback *)((char *)self + 0x1014);
    if (value != 0) callback(data_ov031_02249f00, value, 0);
    VectorizedMemset(record, 0, 0x10);
}
