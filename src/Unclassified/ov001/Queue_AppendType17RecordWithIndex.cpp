#include <globaldefs.h>
ARM
extern "C" void *Queue_AllocateAndAppendNode(void *queue);
extern "C" void *memcpy(void *destination, const void *source, unsigned length);
// Original: arm9/ov001 @ 0x02159210; symbol: func_ov001_02159210; size: 0x40.
extern "C" void Queue_AppendType17RecordWithIndex(void *queue, unsigned first, unsigned second, unsigned third, unsigned finalValue) {
    unsigned char *node = (unsigned char *)Queue_AllocateAndAppendNode(queue);
    if (!node) return;
    *(unsigned *)node = 0x11;
    memcpy(node + 4, &first, 12);
    *(unsigned *)(node + 0x1c) = finalValue;
}
