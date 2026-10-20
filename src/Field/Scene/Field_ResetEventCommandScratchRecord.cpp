#include <globaldefs.h>
ARM
extern "C" void* memset(void*, int, unsigned);
// Original: arm9/ov017 @ 0x021BB088; symbol: Memory_ClearRecordAndMaskedWord; size: 0x3C.
// Clears the 0x1c-byte payload, stores the -1 sentinel at +0x24, and applies the observed mask sequence to +0x28.
extern "C" void Field_ResetEventCommandScratchRecord(unsigned* record) {
    record[0] = 0;
    record[1] = 0;
    memset((unsigned char*)record + 8, 0, 0x1c);
    record[9] = 0xffffffff;
    record[10] &= 0xf8000000u;
    record[10] &= 0x07ffffffu;
}
