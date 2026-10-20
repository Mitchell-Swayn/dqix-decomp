#include <globaldefs.h>
ARM
extern "C" void Graphics_FillTiled4bppRectangle(void*, int, short, short, short, short);
extern "C" unsigned char* TextLookup_GetGlyphEntryByIndex(unsigned int, int);
extern "C" char* TextLookup_FindMatchingByteKeyEntry(const void*, int);
extern "C" void TextCanvas_RenderStyledTextAndMeasure(void*, int, int, char*, unsigned char, unsigned char, short*, short*, int);
// Original data: arm9/ov023 @ 0x21fdd6c; symbol: data_ov023_021fdd6c.
// Source-defined character literal. Text: "*". Original zero separators, trailing bytes and padding remain unchanged.
// Initial values: "*".
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" unsigned char TextAppendGlyphGrid_TextASTERISK[];
// Original: arm9/ov023 @ 0x021E709C; symbol: DrawIndexedGridCellAndLabel; size: 0x104.
// Draws a tiled grid cell and renders the label selected by its byte index.
extern "C" void DrawIndexedGridCellAndLabel(void* surface, const unsigned char* cells, int index, unsigned char* globals) {
    int tileIndex = index;
    if (tileIndex < 0 || tileIndex >= 0x39) return;
    unsigned char entry = cells[tileIndex];
    int left = tileIndex % 0x13 * 12 + 15;
    int top = tileIndex / 0x13 * 0x13 + 8;
    short right = (short)(left + 12);
    short bottom = (short)(top + 12);
    Graphics_FillTiled4bppRectangle(surface, 1, left, top, right, bottom);
    if (entry == 0xff) return;
    unsigned char* record = TextLookup_GetGlyphEntryByIndex(entry, 1);
    if (entry == 0) record = (unsigned char*)TextLookup_FindMatchingByteKeyEntry(TextAppendGlyphGrid_TextASTERISK, 1);
    struct Scratch { short first; char second[2]; } scratch;
    TextCanvas_RenderStyledTextAndMeasure(surface, (short)left, (short)top, *(char**)record, 12, 15, (short*)scratch.second, &scratch.first, 1);
}
