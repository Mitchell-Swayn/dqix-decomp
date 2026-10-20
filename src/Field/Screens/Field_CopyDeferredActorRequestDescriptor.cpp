#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021A7C28; symbol: CopyPackedRecordFieldsToDestination; size: 0x64.
// Copies packed byte/halfword/word fields from source offsets 0 through 0x14 to destination offsets +0x0C through +0x20.
extern "C" void Field_CopyDeferredActorRequestDescriptor(void *destination, const void *source) {
    unsigned char *dst = (unsigned char *)destination;
    const unsigned char *src = (const unsigned char *)source;
    dst[0xc] = src[0];
    dst[0xd] = src[1];
    *(unsigned short *)(dst + 0xe) = *(const unsigned short *)(src + 2);
    *(unsigned short *)(dst + 0x10) = *(const unsigned short *)(src + 4);
    *(unsigned int *)(dst + 0x14) = *(const unsigned int *)(src + 8);
    dst[0x18] = src[0xc];
    dst[0x19] = src[0xd];
    dst[0x1a] = src[0xe];
    dst[0x1b] = src[0xf];
    *(short *)(dst + 0x1c) = *(const short *)(src + 0x10);
    dst[0x1e] = src[0x12];
    *(unsigned int *)(dst + 0x20) = *(const unsigned int *)(src + 0x14);
}
