#include <globaldefs.h>
ARM
extern "C" void *memset(void *dst, int value, unsigned length);
// Original: arm9/ov000 @ 0x02157D14; symbol: Combat_ResetRecordAndInvalidateIndex; size: 0x28.
// Clears the first 0x30 bytes, sets signed halfword +0x1C to -1, and clears word +0x30; caller is combat reset processing.
extern "C" void Combat_InitializeSourceResultRecord(void *object) {
    memset(object, 0, 0x30);
    *(short *)((char *)object + 0x1c) = -1;
    *(unsigned *)((char *)object + 0x30) = 0;
}
