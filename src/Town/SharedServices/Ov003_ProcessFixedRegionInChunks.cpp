#include <globaldefs.h>
ARM
extern "C" void Network_QueueTwelveByteDataChunk(unsigned char, void *, unsigned int, unsigned int, unsigned int *);
// Original: arm9/ov003 @ 0x02172518; symbol: func_ov003_02172518; size: 0x58.
extern "C" void Ov003_ProcessFixedRegionInChunks(char *object, int usePrimary, int unused) {
    unsigned int offset = 0;
    char *destination;
    if (usePrimary) destination = object + 0x1c0;
    else destination = object + 0x380;
    while (offset < 0xe0) {
        unsigned int consumed;
        Network_QueueTwelveByteDataChunk(*(unsigned char *)(object + 0x199), destination, 0xe0, offset, &consumed);
        offset += consumed;
    }
}
