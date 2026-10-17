#include <globaldefs.h>
ARM
extern "C" void func_ov004_02154618(void *);
extern "C" void *HasTypeSixAtResolvedHandle(void *state, unsigned index);
extern "C" void func_ov023_021f809c(void *, void *);
// Original: arm9/ov004 @ 0x02154718; symbol: func_ov004_02154718; size: 0x30.
extern "C" int Unclassified_CheckType37AndProcessResolvedHandle(void *state) {
    func_ov004_02154618(state);
    void *handle = HasTypeSixAtResolvedHandle(state, 0x37);
    if (handle != 0)
        func_ov023_021f809c(handle, state);
    return 0;
}
