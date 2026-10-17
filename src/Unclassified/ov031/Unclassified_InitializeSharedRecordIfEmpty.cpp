#include <globaldefs.h>
ARM

extern "C" void VectorizedMemset(void *, int, unsigned int);
extern "C" void func_ov031_02207ce0(unsigned int value);
extern "C" unsigned char data_ov031_0224e5b4[];

// Original: arm9/ov031 @ 0x02211BD4; symbol: func_ov031_02211bd4; size: 0x64.
extern "C" void Unclassified_InitializeSharedRecordIfEmpty(void *record, unsigned short value, void *unused, unsigned int callbackValue) {
    if (*(void **)(data_ov031_0224e5b4 + 4) != 0) {
        return;
    }
    VectorizedMemset(record, 0, 0x64);
    *(unsigned short *)((char *)record + 8) = value;
    *(unsigned short *)((char *)record + 0xa) = 1;
    *(unsigned short *)((char *)record + 4) = 1;
    *(unsigned short *)((char *)record + 6) = 0;
    *((unsigned char *)record + 0xc) = 0;
    *(unsigned int *)((char *)record + 0x10) = 0;
    *(void **)(data_ov031_0224e5b4 + 4) = record;
    func_ov031_02207ce0(callbackValue);
}
