#include <globaldefs.h>
ARM
extern "C" void *FindEntryWithHalfwordTen(void);
extern "C" void *func_ov023_021fbdec(void *);
// Original: arm9/ov004 @ 0x02157088; symbol: func_ov004_02157088; size: 0x1C.
extern "C" void *Unclassified_TransformAvailableGlobalPointer(void) {
    void *pointer = FindEntryWithHalfwordTen();
    if (pointer == 0)
        return 0;
    return func_ov023_021fbdec(pointer);
}
