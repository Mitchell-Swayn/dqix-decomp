#include <globaldefs.h>
ARM
struct Font; struct Set;
extern "C" unsigned FindLinkedCharacterRangeForKey(Font*, unsigned);
extern "C" const unsigned char* FindThreeByteRecordWithinLinkedIDRange(Set** p,unsigned id);
extern "C" void Graphics_ResolveIndexedFontGlyph(void* a, int b, int c, int d, unsigned short e, unsigned int f);
extern "C" char *data_ov031_02290d38;
// Original: arm9/ov031 @ 0x0223C8D4; symbol: func_ov031_0223c8d4; size: 0xAC.
extern "C" void Graphics_DrawFixedWidthCenteredText(void *target, int x, int y, int value, int advance, const unsigned short *text, unsigned fontIndex) {
    if (!*text) return;
    do {
        char *font = data_ov031_02290d38 + fontIndex * 8;
        unsigned glyph = FindLinkedCharacterRangeForKey((Font*)font, *text);
        if (glyph == 0xffff) glyph = *(unsigned short*)(*(char**)font + 2);
        const unsigned char *metrics = FindThreeByteRecordWithinLinkedIDRange((Set**)font, glyph);
        Graphics_ResolveIndexedFontGlyph(target, x + ((advance - *(signed char*)(metrics + 2)) >> 1), y, value, *text, fontIndex);
        text++;
        x += advance;
    } while (*text);
}
