#include <globaldefs.h>
ARM
extern "C" void *ReadPrimaryOrFallbackPointerAt64(void);
extern "C" void func_ov031_0220520c(void *, unsigned int);
// Original: arm9/ov031 @ 0x0220529C; symbol: func_ov031_0220529c; size: 0x18.
extern "C" void ForwardGlobalPrimaryPointerAndSecondArgument(unsigned int unused, unsigned int value) {
    func_ov031_0220520c(ReadPrimaryOrFallbackPointerAt64(), value);
}
