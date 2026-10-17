#include <globaldefs.h>
ARM
extern "C" void *func_ov011_021849c8(void *);
extern "C" void *func_ov023_021f6880(void *, unsigned int);
extern "C" unsigned int OV023_ReadHalfwordField04(void *);
extern "C" void *OV023_GetEmbeddedField20(void *);
// Original: arm9/ov004 @ 0x0216EA38; symbol: func_ov004_0216ea38; size: 0x3C.
extern "C" void *OV004_GetTypeFourEmbeddedField(void *state, unsigned int key) {
    void *context = func_ov011_021849c8(state);
    void *object = func_ov023_021f6880(context, key);
    if (object == 0) goto fail;
    if (OV023_ReadHalfwordField04(object) != 4) goto fail;
    return OV023_GetEmbeddedField20(object);
fail:
    return 0;
}
