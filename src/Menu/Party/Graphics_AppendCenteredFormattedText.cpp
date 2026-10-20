#include <globaldefs.h>
ARM
extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const char *, int);
extern "C" int TextMarkup_AppendXPositionTag(char *, int);
extern "C" int Text_AppendFormatString(char *, const char *);
extern "C" int TextMarkup_AppendWidthTag(char *, int);
// Original: arm9/ov002 @ 0x0215B8C8; symbol: func_ov002_0215b8c8; size: 0x50.
extern "C" void Graphics_AppendCenteredFormattedText(char **text, const char *format, unsigned int font) {
    int width = TextLayout_ComputeWidthWithGlyphSpacing(format, font & 0xff);
    int aligned = (width + 0x17) & ~7;
    int padding = (aligned - width) >> 1;
    TextMarkup_AppendXPositionTag(*text, padding);
    Text_AppendFormatString(*text, format);
    TextMarkup_AppendWidthTag(*text, padding - 5);
}
