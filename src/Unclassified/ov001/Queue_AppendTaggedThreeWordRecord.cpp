#include <globaldefs.h>
ARM
extern "C" void *func_ov001_02158dcc(void *queue);
extern "C" void *memcpy(void *destination, const void *source, unsigned length);
// Original: arm9/ov001 @ 0x02158F30; symbol: func_ov001_02158f30; size: 0x34.
extern "C" void Queue_AppendTaggedThreeWordRecord(void *queue, unsigned first, unsigned second, unsigned third) {
    unsigned char *node = (unsigned char *)func_ov001_02158dcc(queue);
    if (!node) return;
    *(unsigned *)node = 2;
    memcpy(node + 0x10, &first, 12);
}
