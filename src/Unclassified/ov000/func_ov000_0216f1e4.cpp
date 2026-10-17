#include <globaldefs.h>
ARM
extern "C" void _ZN8Vector3iaSERKS_(void *self, const void *other);
// Original: arm9/ov000 @ 0x0216F1E4; symbol: func_ov000_0216f1e4; size: 0x24.
extern "C" void func_ov000_0216f1e4(void *object, const void *vector, unsigned first, unsigned second) {
    _ZN8Vector3iaSERKS_((char *)object + 0x264, vector);
    *(unsigned *)((char *)object + 0x270) = first;
    *(unsigned *)((char *)object + 0x274) = second;
}
