#include <globaldefs.h>
ARM
extern "C" void *ReadGlobalAt02100044(void);
extern "C" void MoveQueuedRecordAndApplySourceValue(void *, const void *, short);
struct TaggedSourceRecord {
    unsigned char tag;
    unsigned char padding[3];
    short value;
    unsigned char trailing[0xe];
};
// Original: arm9/ov017 @ 0x021CC050; symbol: func_ov017_021cc050; size: 0x30.
extern "C" void Resource_MoveQueuedRecordWithTaggedInput(short value) {
    void *destination = ReadGlobalAt02100044();
    TaggedSourceRecord source;
    source.tag = 0x82;
    source.value = value;
    MoveQueuedRecordAndApplySourceValue(destination, &source, 0);
}
