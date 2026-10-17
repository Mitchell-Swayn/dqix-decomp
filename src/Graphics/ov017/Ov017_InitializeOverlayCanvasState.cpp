#include <globaldefs.h>
extern "C" void InitializeRecordGridAndFlagDefaults(void *);
extern "C" void Graphics_InitializeCanvasTransferState(char *);
extern "C" void TextCanvas_InitializeLayoutAndTransferDefaults(unsigned char *);
// Original: arm9/ov017 @ 0x021A5B48; symbol: func_ov017_021a5b48; size: 0x64.
extern "C" void Ov017_InitializeOverlayCanvasState(char *object) {
    InitializeRecordGridAndFlagDefaults(*(void **)(object + 0x4090));
    int i;
    for (i = 0; i < 2; i++) Graphics_InitializeCanvasTransferState(object + 0x4094 + i * 0x20);
    TextCanvas_InitializeLayoutAndTransferDefaults((unsigned char *)(object + 0x40d4));
    *(int *)(object + 0x41b8) = 0;
    *(int *)(object + 0x41bc) = -1;
    *(int *)(object + 0x41b4) = 0;
    *(int *)(object + 0x41c0) = 0;
}
