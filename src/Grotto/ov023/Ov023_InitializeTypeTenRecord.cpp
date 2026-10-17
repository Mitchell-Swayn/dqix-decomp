#include <globaldefs.h>
extern "C" void ResetRecordWithInvalidIndex(void*);
extern "C" void InitializeRecordBuffersAndEnabledByte(unsigned char*);
extern "C" void* memset(void*, int, unsigned);
extern "C" void func_ov023_021faa60(void*, void*);
// Original: arm9/ov023 @ 0x021FA760; symbol: func_ov023_021fa760; size: 0x74.
extern "C" ARM int Ov023_InitializeTypeTenRecord(void* record, void* owner, unsigned short valueA, unsigned short valueB, unsigned first, unsigned second, unsigned mode) {
    ResetRecordWithInvalidIndex(record);
    *(unsigned short*)((char*)record + 4) = 10;
    *(unsigned short*)((char*)record + 6) = valueA;
    *(unsigned short*)((char*)record + 8) = valueB;
    *(unsigned short*)((char*)record + 0xa) = 0;
    *(unsigned*)((char*)record + 0x20) = first;
    *(unsigned*)((char*)record + 0x10) = second;
    InitializeRecordBuffersAndEnabledByte((unsigned char*)record + 0x24);
    memset((char*)record + 0x78, 0, 0x10);
    *((unsigned char*)record + 0x74) = (unsigned char)mode;
    func_ov023_021faa60(record, owner);
    return 1;
}
