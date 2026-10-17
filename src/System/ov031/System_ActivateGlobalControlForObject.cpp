#include <globaldefs.h>
ARM
extern "C" int func_ov031_0223a5bc();
extern "C" void func_ov031_0223e2c0(unsigned, void*, unsigned char*, unsigned);
extern "C" unsigned data_ov031_02290c44;
// Original: arm9/ov031 @ 0x02227804; symbol: func_ov031_02227804; size: 0x3C.
extern "C" void System_ActivateGlobalControlForObject(void* object) {
    if (!func_ov031_0223a5bc()) return;
    unsigned char* control = (unsigned char*)data_ov031_02290c44;
    unsigned char* region = control + 0x1e000;
    region[0x2a1] = 1;
    func_ov031_0223e2c0(0, object, region, 1);
}
