#include <globaldefs.h>
ARM
extern "C" void* data_ov025_021ef988[4];
extern "C" void InitializeObjectStateFields(void*);
extern "C" void func_ov025_021e2f54(void*, int, int);
// Original: arm9/ov025 @ 0x021E3048; symbol: func_ov025_021e3048; size: 0x3C.
extern "C" int RegisterAndInitializeIndexedRecord(void* unused0, int index, void* unused2, int value) {
    char* records = (char*)data_ov025_021ef988[3];
    void* record = records + 0x540;
    InitializeObjectStateFields(record);
    *(int*)(records + 0x540) = index;
    func_ov025_021e2f54(record, index, value);
    return 1;
}
