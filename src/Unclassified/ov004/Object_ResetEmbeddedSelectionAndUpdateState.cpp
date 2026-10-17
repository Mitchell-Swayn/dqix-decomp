#include <globaldefs.h>
ARM
extern "C" void *ReadWordFieldAtOffset1C(void *);
extern "C" void ResetGlobalOwnerAndEmbeddedSelectionState(void *);
extern "C" void func_ov004_02164738(void *);
// Original: arm9/ov004 @ 0x02165BE4; symbol: func_ov004_02165be4; size: 0x20.
extern "C" int Object_ResetEmbeddedSelectionAndUpdateState(void *object) {
    void *record = ReadWordFieldAtOffset1C(object);
    ResetGlobalOwnerAndEmbeddedSelectionState(record);
    func_ov004_02164738(object);
    return 0;
}
