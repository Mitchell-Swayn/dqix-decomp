#include <globaldefs.h>
ARM
extern "C" void func_ov031_0223d8d8(unsigned value);
// Original: arm9/ov031 @ 0x0223D918; symbol: func_ov031_0223d918; size: 0x10.
extern "C" void func_ov031_0223d918(void *object) {
    func_ov031_0223d8d8(*(unsigned *)((char *)object + 4));
}
