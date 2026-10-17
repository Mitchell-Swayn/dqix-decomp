#include <globaldefs.h>
extern "C" void Graphics_ResetLayerWrapper(int); extern "C" void TextCanvas_InitializeLayoutAndTransferDefaults(int);
ARM
// Original: arm9/main @ 0x0204C754; symbol: func_0204c754; size: 0x1C.
extern "C" void ResetEmbeddedResourceAndRecord(int p) { Graphics_ResetLayerWrapper(p+200); TextCanvas_InitializeLayoutAndTransferDefaults(p); }
