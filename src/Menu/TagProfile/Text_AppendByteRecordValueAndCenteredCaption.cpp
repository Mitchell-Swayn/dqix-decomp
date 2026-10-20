#include <globaldefs.h>
extern "C" void TextMarkup_AppendFrameTag(void*, int, int, int, int, int),TextMarkup_AppendCursorTag(void*, int),Text_AppendFormattedIntegerAndStringFragment(void*, int, const void*),Text_AppendFormatString(void*, const void*),TextMarkup_AppendPaletteTag(void*,int);
extern "C" const void* MessageTextTable_FindTextById(void*, short);
struct ProfilePageBits { unsigned short index : 5; unsigned short value : 11; };
extern "C" void* TextContext_GetSharedInstance(void*);
extern "C" void TextContext_SetNumericArgument(void*,int,int),TextContext_SetNumericArgumentWidth(void*,int,int),TextContext_SetNumericArgumentAlignment(void*,int,int),TextMarkup_AppendSizeTag(void*,int),TextMarkup_AppendPaletteTagForType(void*,int),Text_AppendFormattedXYPair(void*,int,int);
extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const void*,int);
// Format a numeric profile value and center its localized caption.
// Original: arm9/ov012 @ 0x0218A374; symbol: func_ov012_0218a374; size: 0xC4.
extern "C" void Text_AppendByteRecordValueAndCenteredCaption(unsigned char* screen, void* output, int) {
    if (!output) return;
    void* formatter = TextContext_GetSharedInstance(screen);
    TextContext_SetNumericArgument(formatter, 0, screen[0x13ff]);
    TextContext_SetNumericArgumentWidth(formatter, 0, 2);
    TextContext_SetNumericArgumentAlignment(formatter, 0, 1);
    TextMarkup_AppendSizeTag(output, 12);
    short labelId = 102;
    if (screen[0x1371] == 9) labelId = 105;
    Text_AppendFormattedIntegerAndStringFragment(output, 0, MessageTextTable_FindTextById(screen + 0x133c, labelId));
    const void* caption = MessageTextTable_FindTextById(screen + 0x133c, 40);
    int textWidth = TextLayout_ComputeWidthWithGlyphSpacing(caption, 0);
    Text_AppendFormattedXYPair(output, (72 - textWidth) >> 1, 1);
    Text_AppendFormatString(output, caption);
}
