#include <globaldefs.h>
ARM
extern "C" void Graphics_UpdateActiveTransfersAndEnabledWindow(void *);
// Original: arm9/ov017 @ 0x021BABC8; symbol: func_ov017_021babc8; size: 0x18.
extern "C" void Field_UpdateChurchServiceTransfersAndWindow(void *object) {
    void *resource = *(void **)((unsigned char *)object + 0x1c);
    if (resource)
        Graphics_UpdateActiveTransfersAndEnabledWindow(resource);
}
