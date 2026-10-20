#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F86DC; symbol: Unclassified_GetWordAtOffset2C; size: 0x8.
// Returns the word stored at object offset 0x2c.
extern "C" unsigned MenuNumberLabel_GetValue(const void* object) {
    return *(const unsigned*)((const unsigned char*)object + 0x2c);
}
