#include <globaldefs.h>
ARM
extern "C" void Overlay_PopAndDestroyObject(void *);
// Original: arm9/ov017 @ 0x021B2F4C; symbol: Overlay_PopAndDestroyObjectAndSetByte1; size: 0x18.
// Calls Overlay_PopAndDestroyObject and then sets byte +1 to one.
extern "C" int Overlay_PopAndDestroyObjectAndSetByte1(unsigned char *p) {
    Overlay_PopAndDestroyObject(p);
    p[1] = 1;
    return 1;
}
