#include <globaldefs.h>
ARM
extern "C" void* GameResources_GetInstance();
extern "C" void InitializeSelectionControlRecord(void*);
extern "C" void func_ov017_021a932c(void*, int);
extern "C" void AppendLinkedNodeAndMarkActive(unsigned*, unsigned);
// Original: arm9/ov017 @ 0x021A8614; symbol: func_ov017_021a8614; size: 0x5C.
extern "C" void Resource_CreateLinkedByteRecord(unsigned unused, int value, unsigned char byte1, unsigned char byte2, unsigned byte3, unsigned byte4) {
    char* resources = (char*)GameResources_GetInstance() + 0x3000;
    unsigned* list = *(unsigned**)(resources + 0x6fc);
    char* record = *(char**)(resources + 0xb7c);
    InitializeSelectionControlRecord(record);
    func_ov017_021a932c(record, value);
    record[0x18] = byte1;
    record[0x19] = byte2;
    record[0x1a] = byte3;
    record[0x1b] = byte4;
    AppendLinkedNodeAndMarkActive(list, (unsigned)record);
}
