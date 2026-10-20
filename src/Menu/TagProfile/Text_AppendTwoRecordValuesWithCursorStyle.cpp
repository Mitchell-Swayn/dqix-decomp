#include <globaldefs.h>
extern "C" void TextMarkup_AppendFrameTag(void*, int, int, int, int, int),TextMarkup_AppendCursorTag(void*, int),Text_AppendFormattedIntegerAndStringFragment(void*, int, const void*),Text_AppendFormatString(void*, const void*),TextMarkup_AppendPaletteTag(void*,int);
extern "C" const void* MessageTextTable_FindTextById(void*, short);
struct ProfilePageBits { unsigned short index : 5; unsigned short value : 11; };
// Render the pair of localized labels for this profile page.
// Original: arm9/ov012 @ 0x02189FB0; symbol: func_ov012_02189fb0; size: 0xA4.
extern "C" void Text_AppendTwoRecordValuesWithCursorStyle(unsigned char* screen, void* output, int reset) {
    if (!output) return;
    int style = *(int*)(screen + 0x13f8);
    if (reset) TextMarkup_AppendFrameTag(output, style, 8, 5, 5, 5);
    TextMarkup_AppendCursorTag(output, style);
    Text_AppendFormattedIntegerAndStringFragment(output, 0, MessageTextTable_FindTextById(screen + 0x133c, 16));
    Text_AppendFormatString(output, *(const void**)(screen + 0x1378));
    Text_AppendFormattedIntegerAndStringFragment(output, 1, MessageTextTable_FindTextById(screen + 0x133c, 17));
}
