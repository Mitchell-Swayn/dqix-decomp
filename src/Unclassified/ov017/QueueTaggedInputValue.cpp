#include <globaldefs.h>
ARM
struct QueuedSource { unsigned char tag; unsigned char padding[3]; void *value; unsigned char tail[12]; };
extern "C" void *ReadGlobalAt02100044(void);
extern "C" void MoveQueuedRecordAndApplySourceValue(void *object, const void *source, short value);
// Original: arm9/ov017 @ 0x021CEA34; symbol: func_ov017_021cea34; size: 0x30.
extern "C" void QueueTaggedInputValue(void *value) {
    void *object = ReadGlobalAt02100044();
    QueuedSource source;
    source.tag = 0x31;
    source.value = value;
    MoveQueuedRecordAndApplySourceValue(object, &source, 0);
}
