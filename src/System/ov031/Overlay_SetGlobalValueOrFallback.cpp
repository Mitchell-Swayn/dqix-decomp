#include <globaldefs.h>
ARM
extern "C" volatile unsigned data_ov031_0224e590;
extern "C" int Ov031_IsGlobalModeTwoOrThree();
extern "C" void func_ov031_02211864(int, int);
// Original: arm9/ov031 @ 0x022110F0; symbol: func_ov031_022110f0; size: 0x48.
extern "C" void Overlay_SetGlobalValueOrFallback(int value) {
    if (!*(void**)&data_ov031_0224e590) goto fallback;
    if (Ov031_IsGlobalModeTwoOrThree()) goto fallback;
    goto success;
fallback:
    func_ov031_02211864(9, -2);
    return;
success:
    *(int*)((char*)*(void**)&data_ov031_0224e590 + 0x3c) = value;
}
