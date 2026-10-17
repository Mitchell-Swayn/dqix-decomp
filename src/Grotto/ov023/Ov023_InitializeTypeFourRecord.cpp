#include <globaldefs.h>
extern "C" void ResetRecordWithInvalidIndex(void*);
extern "C" void func_ov023_021fa5a0(void*, void*);
// Original: arm9/ov023 @ 0x021FA298; symbol: func_ov023_021fa298; size: 0x5C.
extern "C" ARM int Ov023_InitializeTypeFourRecord(void* record, void* owner, unsigned short valueA, unsigned short valueB, unsigned first, unsigned second, unsigned mode) {
    ResetRecordWithInvalidIndex(record);
    *(unsigned short*)((char*)record + 4) = 4;
    *(unsigned short*)((char*)record + 6) = valueA;
    *(unsigned short*)((char*)record + 8) = valueB;
    *(unsigned short*)((char*)record + 0xa) = 0;
    *(unsigned*)((char*)record + 0x28) = first;
    *(unsigned*)((char*)record + 0x10) = second;
    *((unsigned char*)record + 0x2c) = (unsigned char)mode;
    func_ov023_021fa5a0(record, owner);
    return 1;
}
