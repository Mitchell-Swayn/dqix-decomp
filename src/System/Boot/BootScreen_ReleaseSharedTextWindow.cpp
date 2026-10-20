// Retrieve the overlay controller, then reset its pending work.
extern "C" void* TextContext_GetSharedInstance();
extern "C" void TextWindow_ReleaseFrameAndResetRendering(void* controller);
// Original: arm9/ov020 @ 0x0218B700; symbol: func_ov020_0218b700; size: 0x10.
extern "C" void BootScreen_ReleaseSharedTextWindow() { TextWindow_ReleaseFrameAndResetRendering(TextContext_GetSharedInstance()); }
