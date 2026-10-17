#include <globaldefs.h>
ARM
extern "C" struct AllowedValues { int value[3]; };
extern "C" AllowedValues data_ov004_0216fa80;
extern "C" void func_ov004_0215482c(void*);
extern "C" void* HasTypeSixAtResolvedHandle(void*, unsigned);
extern "C" void func_ov023_021f809c(void*, void*);
// Original: arm9/ov004 @ 0x02154984; symbol: func_ov004_02154984; size: 0x60.
extern "C" int ProcessAllowedResolvedHandles(void* state) {
    func_ov004_0215482c(state);
    AllowedValues values = data_ov004_0216fa80;
    for (int i = 0; values.value[i] >= 0;) {
        void* handle = HasTypeSixAtResolvedHandle(state, values.value[i]);
        if (handle != 0) {
            func_ov023_021f809c(handle, state);
            ++i;
        }
    }
    return 0;
}
