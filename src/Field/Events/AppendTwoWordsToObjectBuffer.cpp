#include <globaldefs.h>
ARM
extern "C" void Script_CopyTaggedValue(void *, const void *);
// Original: arm9/ov017 @ 0x021D4A38; symbol: func_ov017_021d4a38; size: 0x2C.
extern "C" void AppendTwoWordsToObjectBuffer(void *object, unsigned int first, unsigned int second, unsigned int unused) {
    void *destination = *(void **)((char *)object + 0x14);
    *(void **)((char *)object + 0x14) = (char *)destination + 8;
    Script_CopyTaggedValue(destination, &first);
}
