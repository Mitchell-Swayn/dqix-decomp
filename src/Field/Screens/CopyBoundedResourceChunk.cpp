#include <globaldefs.h>
ARM
extern "C" void *memcpy(void *, const void *, unsigned int);
// Original: arm9/ov017 @ 0x021D2368; symbol: func_ov017_021d2368; size: 0x54.
extern "C" void CopyBoundedResourceChunk(void *unused0, const unsigned char *source, void *unused2, void *owner) {
    unsigned char *resource = *(unsigned char **)((unsigned char *)owner + 0x3b30);
    if (resource[2] == 0) return;
    unsigned char *destination = *(unsigned char **)(resource + 0x288);
    if (destination == 0) return;
    unsigned offset = ((unsigned)*(unsigned short *)(source + 4) << 16) >> 18;
    int length = 0xe;
    if (offset + 0xe > 0x2e0) length = 0x2e0 - offset;
    if (length < 0) return;
    memcpy(destination + offset, source + 6, length);
}
