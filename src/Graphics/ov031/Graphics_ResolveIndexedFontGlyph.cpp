#include <globaldefs.h>
ARM
extern "C" void ResolveFontGlyphBitmapAndFallbackMetrics(void*, const void*, int, int, int, unsigned int);
struct Glyph { unsigned int a, b; };
extern "C" Glyph* data_ov031_02290d38;
// Original: arm9/ov031 @ 0x0223C898; symbol: func_ov031_0223c898; size: 0x3C.
extern "C" void Graphics_ResolveIndexedFontGlyph(void* a, int b, int c, int d, unsigned short e, unsigned int f) {
    ResolveFontGlyphBitmapAndFallbackMetrics(a, data_ov031_02290d38 + f, b, c, d, e);
}
