#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov017_021d83ac[];
extern "C" void Ov002_InitializeSelectionFlags(void *);
// Original: arm9/ov017 @ 0x021A5AB0; symbol: func_ov017_021a5ab0; size: 0x20.
extern "C" void Unclassified_ProcessGlobalPointerIfPresent(void) {
    void *object = *(void **)data_ov017_021d83ac;
    if (object != 0)
        Ov002_InitializeSelectionFlags(object);
}
