#include <globaldefs.h>
ARM
extern "C" void func_ov017_021a4368(void *object, void *field);
// Original: arm9/ov017 @ 0x021A4358; symbol: func_ov017_021a4358; size: 0x10.
extern "C" void Ov017_ForwardWithFirstField(void *object) {
    func_ov017_021a4368(object, *(void **)object);
}
