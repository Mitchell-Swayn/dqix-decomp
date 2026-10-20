#include <globaldefs.h>
ARM
extern "C" void TextCanvas_ClearDisplayLayerBuffers(unsigned char *);
extern "C" void TextCanvas_CopyAllDisplayPartsToLayers(unsigned char *);
extern "C" void Graphics_CleanConfiguredDestinationCacheForEachThirtyTwoByteEntry(unsigned char *);
// Original: arm9/ov003 @ 0x02167548; symbol: func_ov003_02167548; size: 0x34.
extern "C" void Graphics_CleanupTransferState(unsigned char *p) {
    if (*(unsigned char *)(p + 0x74) == 0 || *(unsigned int *)(p + 0x10) == 0) return;
    TextCanvas_ClearDisplayLayerBuffers(*(unsigned char **)(p + 0x10));
    TextCanvas_CopyAllDisplayPartsToLayers(*(unsigned char **)(p + 0x10));
    Graphics_CleanConfiguredDestinationCacheForEachThirtyTwoByteEntry(*(unsigned char **)(p + 0x10));
}
