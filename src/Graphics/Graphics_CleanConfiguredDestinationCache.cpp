#include <globaldefs.h>
void CleanInvalidateCacheRange(const void*, unsigned int);
extern "C" {
extern const volatile unsigned int data_020e7b98[2][4];
// Original: arm9/main @ 0x0204B04C; symbol: func_0204b04c; size: 0x3C.
void Graphics_CleanConfiguredDestinationCache(unsigned char* entry, void* destination)
{
    if (destination == 0) destination = *reinterpret_cast<void**>(entry + 0x14);
    if (destination == 0) return;
    unsigned char category = entry[0x1f];
    const volatile unsigned int* row = data_020e7b98[category];
    int index = *reinterpret_cast<int*>(entry + 0x18);
    unsigned int length = row[index];
    CleanInvalidateCacheRange(destination, length);
}
}
