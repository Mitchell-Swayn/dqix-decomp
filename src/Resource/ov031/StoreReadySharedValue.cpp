#include <globaldefs.h>
ARM
extern "C" void* volatile data_ov031_0224e580;
extern "C" int func_ov031_022102c8();
extern "C" void StoreValueAtIndirectOffsetA0C(void*);
extern "C" void func_ov031_0220fdec();
// Original: arm9/ov031 @ 0x0220FE44; symbol: func_ov031_0220fe44; size: 0x5C.
extern "C" int StoreReadySharedValue(void* value) {
    if (data_ov031_0224e580 == 0) return 0;
    if (!func_ov031_022102c8()) return 0;
    *(unsigned*)((char*)data_ov031_0224e580 + 0x2c) = 0;
    *(void**)((char*)data_ov031_0224e580 + 0x28) = value;
    StoreValueAtIndirectOffsetA0C((void*)func_ov031_0220fdec);
    return 1;
}
