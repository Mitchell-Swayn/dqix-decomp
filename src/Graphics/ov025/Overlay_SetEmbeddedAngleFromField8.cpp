#include <globaldefs.h>
ARM
extern "C" unsigned ReadOverlayControlSecondWord();
extern "C" void* GetEmbeddedFieldC18(unsigned char*);
extern "C" void SetAngleAndCacheTrig(void*, unsigned);
// Original: arm9/ov025 @ 0x021E8510; symbol: func_ov025_021e8510; size: 0x38.
extern "C" int Overlay_SetEmbeddedAngleFromField8(unsigned char* p) {
    unsigned control = ReadOverlayControlSecondWord();
    if (control == 0) return 1;
    void* embedded = GetEmbeddedFieldC18((unsigned char*)control);
    if (embedded == 0) return 1;
    SetAngleAndCacheTrig(embedded, *(unsigned*)(p + 8));
    return 1;
}
