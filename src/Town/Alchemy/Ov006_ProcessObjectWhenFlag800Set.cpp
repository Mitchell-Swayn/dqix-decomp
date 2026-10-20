#include <globaldefs.h>
ARM
extern "C" void Graphics_RenderOrAppendSharedCanvasText(void *object);
// Original: arm9/ov006 @ 0x021571CC; symbol: func_ov006_021571cc; size: 0x30.
extern "C" void Ov006_ProcessObjectWhenFlag800Set(unsigned char *object) {
    unsigned short value = *(unsigned short *)(object + 0x1258);
    int enabled;
    if (value & 0x800) enabled = 1;
    else enabled = 0;
    if (enabled == 0) return;
    Graphics_RenderOrAppendSharedCanvasText(object + 0xae4);
}
