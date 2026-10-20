#include <globaldefs.h>
ARM
extern "C" void Graphics_RefreshResourcesForSignedModePair(void *);
// Original: arm9/ov003 @ 0x0217F248; symbol: func_ov003_0217f248; size: 0x18.
extern "C" void Inn_TransferServiceSceneGraphics(void *object) {
    void *value = *(void **)((unsigned char *)object + 0xc);
    if (value)
        Graphics_RefreshResourcesForSignedModePair(value);
}
