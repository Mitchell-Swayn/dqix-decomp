#include <globaldefs.h>
ARM
struct Font; struct Set;
extern "C" unsigned Font_FindGlyphIndexForCharacter(Font*, unsigned);
extern "C" const unsigned char* Font_GetGlyphWidthsOrDefault(Set** p,unsigned id);
extern "C" void Graphics_ResolveIndexedFontGlyph(void* a, int b, int c, int d, unsigned short e, unsigned int f);
// Original data: arm9/ov031 @ 0x2290d38; symbol: data_ov031_02290d38.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char *WfcUtilityDestroyTextCanvasServices_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0223C8D4; symbol: func_ov031_0223c8d4; size: 0xAC.
extern "C" void Graphics_DrawFixedWidthCenteredText(void *target, int x, int y, int value, int advance, const unsigned short *text, unsigned fontIndex) {
    if (!*text) return;
    do {
        char *font = WfcUtilityDestroyTextCanvasServices_UnknownRoleZeroInitializedStorage + fontIndex * 8;
        unsigned glyph = Font_FindGlyphIndexForCharacter((Font*)font, *text);
        if (glyph == 0xffff) glyph = *(unsigned short*)(*(char**)font + 2);
        const unsigned char *metrics = Font_GetGlyphWidthsOrDefault((Set**)font, glyph);
        Graphics_ResolveIndexedFontGlyph(target, x + ((advance - *(signed char*)(metrics + 2)) >> 1), y, value, *text, fontIndex);
        text++;
        x += advance;
    } while (*text);
}
