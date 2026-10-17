#include <globaldefs.h>
ARM
extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const char *, int);
extern "C" int Text_AppendFormattedIntegerFragmentAt020EFE78(char *, int);
extern "C" int AppendFormatText(char *, const char *);
extern "C" int Text_AppendFormattedIntegerFragmentAt020EFE91(char *, int);
// Original: arm9/ov002 @ 0x0215B8C8; symbol: func_ov002_0215b8c8; size: 0x50.
extern "C" void func_ov002_0215b8c8(char **text, const char *format, unsigned int font) {
    int width = TextLayout_ComputeWidthWithGlyphSpacing(format, font & 0xff);
    int aligned = (width + 0x17) & ~7;
    int padding = (aligned - width) >> 1;
    Text_AppendFormattedIntegerFragmentAt020EFE78(*text, padding);
    AppendFormatText(*text, format);
    Text_AppendFormattedIntegerFragmentAt020EFE91(*text, padding - 5);
}
