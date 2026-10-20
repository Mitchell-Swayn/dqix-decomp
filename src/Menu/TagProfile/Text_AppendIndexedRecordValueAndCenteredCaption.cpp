#include <globaldefs.h>
extern "C" void TextMarkup_AppendFrameTag(void*, int, int, int, int, int),TextMarkup_AppendCursorTag(void*, int),Text_AppendFormattedIntegerAndStringFragment(void*, int, const void*),Text_AppendFormatString(void*, const void*),TextMarkup_AppendPaletteTag(void*,int);
extern "C" const void* MessageTextTable_FindTextById(void*, short);
struct ProfilePageBits { unsigned short index : 5; unsigned short value : 11; };
extern "C" void* TextContext_GetSharedInstance(void*);
extern "C" void TextContext_SetNumericArgument(void*,int,int),TextContext_SetNumericArgumentWidth(void*,int,int),TextContext_SetNumericArgumentAlignment(void*,int,int),TextMarkup_AppendSizeTag(void*,int),TextMarkup_AppendPaletteTagForType(void*,int),Text_AppendFormattedXYPair(void*,int,int);
extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const void*,int);
// Apply alternate page formatting, then center its localized caption.
// Original: arm9/ov012 @ 0x0218A2B8; symbol: func_ov012_0218a2b8; size: 0xBC.
extern "C" void Text_AppendIndexedRecordValueAndCenteredCaption(unsigned char* screen, void* output, int) {
    if (!output) return;
    TextContext_GetSharedInstance(screen);
    if (screen[0x1371] == 8) TextMarkup_AppendPaletteTagForType(output, 4);
    Text_AppendFormattedIntegerAndStringFragment(output, 0, MessageTextTable_FindTextById(screen + 0x133c, (short)(screen[0x13fe] + 19)));
    if (screen[0x1371] == 8) TextMarkup_AppendPaletteTagForType(output, 0);
    const void* caption = MessageTextTable_FindTextById(screen + 0x133c, 41);
    int textWidth = TextLayout_ComputeWidthWithGlyphSpacing(caption, 0);
    Text_AppendFormattedXYPair(output, (72 - textWidth) >> 1, 1);
    Text_AppendFormatString(output, caption);
}
