#include <globaldefs.h>
#include <std_library_functions.h>
#include <System/Cache.h>
ARM
#pragma optimization_level 4
// Original: arm9/main @ 0x0204A8F4; symbol: func_0204a8f4; size: 0x90.
extern "C" void Graphics_CopyResourceHeaderAndCleanPayloadCache(void *destination, const void *source, unsigned int, unsigned int) {
    unsigned int localLength;
    unsigned char stackBuffer[4];
    memcpy(stackBuffer, source, 4);
    memcpy((char *)destination + 4, (const char *)source + 4, 2);
    memcpy((char *)destination + 6, (const char *)source + 6, 2);
    memcpy((char *)destination + 8, (const char *)source + 8, 2);
    memcpy((char *)destination + 10, (const char *)source + 10, 1);
    memcpy((char *)destination + 11, (const char *)source + 11, 1);
    memcpy(&localLength, (const char *)source + 12, 4);
    CleanInvalidateCacheRange((const char *)source + 16, localLength);
}
