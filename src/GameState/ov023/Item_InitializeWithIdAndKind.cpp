#include <globaldefs.h>
ARM

extern "C" void ResetRecordWithInvalidIndex(char *p);
extern "C" void InitializeTwoWordsAndTwoHalfwords(void *object);

// Original: arm9/ov023 @ 0x021FC1F4; symbol: func_ov023_021fc1f4; size: 0x34.
extern "C" int Item_InitializeWithIdAndKind(void *item, void *owner, unsigned id, unsigned kind) {
    ResetRecordWithInvalidIndex((char *)item);
    *(unsigned short *)((char *)item + 4) = 0x12;
    *(unsigned short *)((char *)item + 6) = id;
    *(unsigned short *)((char *)item + 8) = kind;
    InitializeTwoWordsAndTwoHalfwords((char *)item + 0x20);
    return 1;
}
