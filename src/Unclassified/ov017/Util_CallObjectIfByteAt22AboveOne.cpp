#include <globaldefs.h>
ARM
extern "C" void Graphics_UpdateCountdownAndDrawAttachedObject(void *object);
// Original: arm9/ov017 @ 0x021A185C; symbol: func_ov017_021a185c; size: 0x24.
extern "C" void Util_CallObjectIfByteAt22AboveOne(void *object) {
    if (*(unsigned char *)((char *)object + 0x22) <= 1)
        return;
    void *nested = *(void **)((char *)object + 0x1c);
    if (nested)
        Graphics_UpdateCountdownAndDrawAttachedObject(nested);
}
