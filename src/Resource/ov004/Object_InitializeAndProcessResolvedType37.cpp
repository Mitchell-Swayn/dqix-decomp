#include <globaldefs.h>
ARM
extern "C" void func_ov004_02154748(void *);
extern "C" void *HasTypeSixAtResolvedHandle(void *, unsigned int);
extern "C" void func_ov023_021f809c(void *, void *);
// Original: arm9/ov004 @ 0x021547FC; symbol: func_ov004_021547fc; size: 0x30.
extern "C" int Object_InitializeAndProcessResolvedType37(void *object) {
    func_ov004_02154748(object);
    void *resolved = HasTypeSixAtResolvedHandle(object, 0x37);
    if (resolved)
        func_ov023_021f809c(resolved, object);
    return 0;
}
