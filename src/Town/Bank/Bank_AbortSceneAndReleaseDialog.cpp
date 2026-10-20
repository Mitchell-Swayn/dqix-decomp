#include <globaldefs.h>
ARM
extern "C" void Bank_ReleaseDialogResources(void *);
extern "C" void Overlay_DestroyObjectAndFree(void *);
// Original: arm9/ov003 @ 0x0217E5B0; symbol: func_ov003_0217e5b0; size: 0x2C.
extern "C" void Bank_AbortSceneAndReleaseDialog(void *object) {
    if (*(void **)((unsigned char *)object + 0x20) != 0)
        Bank_ReleaseDialogResources(*(void **)((unsigned char *)object + 0x20));
    Overlay_DestroyObjectAndFree(object);
    ((unsigned char *)object)[1] = 1;
}
