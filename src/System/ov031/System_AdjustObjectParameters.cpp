#include <globaldefs.h>
ARM
extern "C" void Overlay_MapOperationResultForFallbackState(void *object, int value, int first, int second, int extra);
// Original: arm9/ov031 @ 0x022407F8; symbol: func_ov031_022407f8; size: 0x28.
extern "C" void System_AdjustObjectParameters(void *object, int value, int offset, int extra) {
    unsigned char *state = *(unsigned char **)((unsigned char *)object + 0x30);
    Overlay_MapOperationResultForFallbackState(object, value, *(int *)(state + 0x18) + offset, *(int *)(state + 0x0c) - offset, extra);
}
