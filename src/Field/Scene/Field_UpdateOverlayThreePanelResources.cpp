#include <globaldefs.h>
ARM
extern "C" void Inn_DrawStayDialogCanvases(void *object);
// Original: arm9/ov017 @ 0x021BAE80; symbol: func_ov017_021bae80; size: 0x18.
extern "C" void Field_UpdateOverlayThreePanelResources(unsigned char *self) {
    void *object = *(void **)(self + 0x20);
    if (object != 0) Inn_DrawStayDialogCanvases(object);
}
