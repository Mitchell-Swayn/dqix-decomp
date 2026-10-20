#include <globaldefs.h>
ARM
extern "C" void Inn_DrawServiceMenuAndActivePanel(unsigned int);
// Original: arm9/ov003 @ 0x0217F218; symbol: Overlay_ProcessObjectIfField0CNonzero; size: 0x18.
// Passes the object word at offset +0x0C to the processor only when it is nonzero.
extern "C" void Inn_DrawServiceScene(void *obj) {
    unsigned int value = *(unsigned int *)((char *)obj + 0x0c);
    if (value) Inn_DrawServiceMenuAndActivePanel(value);
}
