#include <globaldefs.h>
ARM
extern "C" void Object3D_DrawLinkedOrEnabledEmbeddedObject(unsigned char *);
// Original: arm9/ov017 @ 0x021B65BC; symbol: func_ov017_021b65bc; size: 0x1C.
extern "C" void DrawEmbeddedObjectIfStateThree(unsigned char *object) {
    if (object[0xfc] == 3)
        Object3D_DrawLinkedOrEnabledEmbeddedObject(object + 0xc);
}
