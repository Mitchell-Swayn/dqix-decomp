#include <globaldefs.h>
ARM
extern "C" void Graphics_DrawAndUpdateEmbeddedObject(void *);

// Original: arm9/ov003 @ 0x0217F230; symbol: func_ov003_0217f230; size: 0x18.
extern "C" void Graphics_DrawAndUpdateEmbeddedObjectFromFieldC(void *object) {
    void *value = *(void **)((unsigned char *)object + 0x0c);
    if (value != 0)
        Graphics_DrawAndUpdateEmbeddedObject(value);
}
