#include <globaldefs.h>
ARM
extern "C" void Graphics_DrawOverlay8ObjectWhenEnabled(signed char *object);
// Original: arm9/ov017 @ 0x021C1208; symbol: func_ov017_021c1208; size: 0x18.
extern "C" void RecordsScreen_DrawOptionalPanel(void *object) {
    signed char *p = *(signed char **)((char *)object + 0x1c);
    if (p)
        Graphics_DrawOverlay8ObjectWhenEnabled(p);
}
