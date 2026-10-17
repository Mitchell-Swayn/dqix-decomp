#include <globaldefs.h>
ARM
extern "C" void *data_ov031_0224e580;
extern "C" int Queue_PeekValueWithOptionalBlockingAndIRQGuard(void *, unsigned *, unsigned);
// Original: arm9/ov031 @ 0x0220F68C; symbol: func_ov031_0220f68c; size: 0x54.
extern "C" void PeekAndClearQueuedRecordFields(void) {
    void *queue = data_ov031_0224e580;
    Queue_PeekValueWithOptionalBlockingAndIRQGuard(queue, (unsigned *)((unsigned char *)queue + 0x24), 1);
    void *record = *(void **)((unsigned char *)data_ov031_0224e580 + 0x24);
    if (record == 0) return;
    *(unsigned *)((unsigned char *)record + 0x1c) = 0;
    record = *(void **)((unsigned char *)data_ov031_0224e580 + 0x24);
    *(unsigned *)((unsigned char *)record + 0x20) = 0;
    record = *(void **)((unsigned char *)data_ov031_0224e580 + 0x24);
    *(unsigned *)((unsigned char *)record + 0x24) = 0;
}
