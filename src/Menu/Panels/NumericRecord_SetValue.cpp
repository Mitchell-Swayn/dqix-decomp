#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F6504; symbol: Unclassified_SetWordAtOffset2C; size: 0x8.
// Stores the supplied word at object offset 0x2c.
extern "C" void NumericRecord_SetValue(void* object, unsigned value) {
    *(unsigned*)((unsigned char*)object + 0x2c) = value;
}
