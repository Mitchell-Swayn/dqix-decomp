#include <globaldefs.h>
ARM
extern "C" void *memset(void *, int, unsigned int);
// Original: arm9/ov023 @ 0x021F9C0C; symbol: Memory_ZeroBufferUsingElementCountAndStride; size: 0x24.
// Clears the buffer at +0x20 for (count at +0x24 * 2 * stride at +0x26) bytes.
extern "C" void Memory_ZeroBufferUsingElementCountAndStride(unsigned char *descriptor) {
    unsigned int count = *(unsigned short *)(descriptor + 0x24);
    unsigned int stride = *(unsigned short *)(descriptor + 0x26);
    memset(*(void **)(descriptor + 0x20), 0, (count * 2) * stride);
}
