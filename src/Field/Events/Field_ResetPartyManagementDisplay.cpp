#include <globaldefs.h>
ARM
extern "C" void Graphics_ResetActiveResourceDisplayState(void *resource);
// Original: arm9/ov017 @ 0x021B6B5C; symbol: func_ov017_021b6b5c; size: 0x18.
extern "C" void Field_ResetPartyManagementDisplay(void *object) {
    void *resource = *(void **)((unsigned char *)object + 0x24);
    if (resource) Graphics_ResetActiveResourceDisplayState(resource);
}
