#include <globaldefs.h>
ARM
extern "C" void Font_RenderCharacterWithFallback(void*, const void*, int, int, int, unsigned int);
struct Glyph { unsigned int a, b; };
// Original data: arm9/ov031 @ 0x2290d38; symbol: data_ov031_02290d38.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" Glyph* WfcUtilityDestroyTextCanvasServices_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0223C898; symbol: func_ov031_0223c898; size: 0x3C.
extern "C" void Graphics_ResolveIndexedFontGlyph(void* a, int b, int c, int d, unsigned short e, unsigned int f) {
    Font_RenderCharacterWithFallback(a, WfcUtilityDestroyTextCanvasServices_UnknownRoleZeroInitializedStorage + f, b, c, d, e);
}
