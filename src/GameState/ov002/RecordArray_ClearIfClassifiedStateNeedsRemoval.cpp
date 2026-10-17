#include <globaldefs.h>
ARM

extern "C" void *ReadGlobalValueAt02153637();
extern "C" unsigned char ClassifyContextIdStateAndEntryOwnership(void *object, unsigned id);
extern "C" void RecordArray_ClearMatchingCurrentOwnerEntry(void *p, int id);

// Original: arm9/ov002 @ 0x0215B7D0; symbol: func_ov002_0215b7d0; size: 0x44.
extern "C" int RecordArray_ClearIfClassifiedStateNeedsRemoval(void) {
    void *object = ReadGlobalValueAt02153637();
    unsigned char state = ClassifyContextIdStateAndEntryOwnership(object, 1);
    if (state == 1) return 1;
    if ((unsigned int)state - 3 > 2) return 0;
    RecordArray_ClearMatchingCurrentOwnerEntry(object, 1);
    return -1;
}
