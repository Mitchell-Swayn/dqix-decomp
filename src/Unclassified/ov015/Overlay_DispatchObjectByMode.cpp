#include <globaldefs.h>
ARM
extern "C" void func_ov015_0218e810(void *object);
extern "C" void Graphics_DrawBoneAttachedObjectParts(void *object);
extern "C" void func_ov015_0218ecd8(void *object);
extern "C" void func_ov015_0218edcc(void *object);
extern "C" void Graphics_DrawHandleOrObjectAndCollectCounts(void *object);
// Original: arm9/ov015 @ 0x0218F22C; symbol: func_ov015_0218f22c; size: 0x50.
extern "C" void Overlay_DispatchObjectByMode(void *object) {
    switch (((unsigned char *)object)[0x1c]) {
    case 0: func_ov015_0218e810(object); break;
    case 1: Graphics_DrawBoneAttachedObjectParts(object); break;
    case 3: func_ov015_0218ecd8(object); break;
    case 2: func_ov015_0218edcc(object); break;
    case 4: Graphics_DrawHandleOrObjectAndCollectCounts(object); break;
    }
}
