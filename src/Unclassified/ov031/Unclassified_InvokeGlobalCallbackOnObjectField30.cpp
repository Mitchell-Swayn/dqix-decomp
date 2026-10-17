#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_02290fc8[];
extern "C" void DispatchOverlayObjectCallbacks(void *);
// Original: arm9/ov031 @ 0x02240DF4; symbol: func_ov031_02240df4; size: 0x28.
extern "C" void Unclassified_InvokeGlobalCallbackOnObjectField30(void *object) {
    ((void (*)(void *))(*(void **)data_ov031_02290fc8))(*(void **)((unsigned char *)object + 0x30));
    DispatchOverlayObjectCallbacks(object);
}
