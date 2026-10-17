#include <globaldefs.h>
ARM
extern "C" void func_ov031_022157f8(void*, void*);
extern "C" int RuntimeMemory_CompareByteRanges(const void*, const void*, unsigned);
extern "C" unsigned data_ov031_02249b3c;
// Original: arm9/ov031 @ 0x02215718; symbol: func_ov031_02215718; size: 0x38.
extern "C" int Overlay_IsGeneratedRecordPrefixExpected(void* self) {
    unsigned char buffer[0x18];
    func_ov031_022157f8(self, buffer);
    return RuntimeMemory_CompareByteRanges(buffer, &data_ov031_02249b3c, 8) == 0;
}
