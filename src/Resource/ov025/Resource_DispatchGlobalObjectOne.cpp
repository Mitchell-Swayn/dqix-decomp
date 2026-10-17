#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov025_021ef988[];
extern "C" void func_ov025_021eb6fc(void *object, int value);
// Original: arm9/ov025 @ 0x021E85C8; symbol: func_ov025_021e85c8; size: 0x20.
extern "C" int Resource_DispatchGlobalObjectOne(void) {
    func_ov025_021eb6fc(*(void **)(data_ov025_021ef988 + 0xc), 1);
    return 1;
}
