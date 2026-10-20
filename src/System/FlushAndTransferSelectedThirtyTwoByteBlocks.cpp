#include "std_library_functions.h"
#include "System/Cache.h"
struct TransferStatus { unsigned char state, reserved; unsigned short mask; };
typedef void (*TransferBlock)(const void*, unsigned int, unsigned int);
// Original: arm9/main @ 0x0204AA64; symbol: func_0204aa64; size: 0xE8.
extern "C" int FlushAndTransferSelectedThirtyTwoByteBlocks(TransferStatus* status, TransferBlock transfer, const unsigned char* source)
{
    unsigned int length;
    unsigned int header;
    unsigned char reserved[3];
    memcpy(&header, source, 4);
    memcpy(status, source + 4, 1);
    memcpy(reserved, source + 5, 3);
    memcpy(&length, source + 8, 4);
    if (status->mask == 0xffff) {
        CleanInvalidateCacheRange(source + 12, length);
        transfer(source + 12, 0, length);
    } else {
        const unsigned char* blocks = source + 12;
        unsigned char mask = status->mask;
        for (int i = 0; i < 16; i++) {
            if (mask & 1) {
                CleanInvalidateCacheRange(blocks + i * 32, 32);
                transfer(blocks + i * 32, i << 5, 32);
            }
            mask >>= 1;
        }
    }
    return 0;
}
