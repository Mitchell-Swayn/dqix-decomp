#pragma force_active on
extern "C" {
int TextLayout_ComputeWidthWithGlyphSpacing(const char *, int);
int Text_AppendFormattedXYPair(char *, int, int);
int Text_AppendFormatString(char *, const char *);
int TextMarkup_AppendSDRCTag(char *, int, int, int, int, int);
}
// Original: arm9/ov023 @ 0x021ED254; symbol: func_ov023_021ed254; size: 0x100.
extern "C" void MenuNotice_FormatCenteredTitleAndRevealMask(void *owner, char *destination)
{
    char *self = (char *)owner;
    char *output = destination;
    if (!output) return;
    char *title = *(char **)(self + 0x20) + *(unsigned char *)(self + 0x28) * 0x244 + 0xC;
    int x = (160 - TextLayout_ComputeWidthWithGlyphSpacing(title, 1)) / 2;
    if (x < 0) x = 0;
    Text_AppendFormattedXYPair(output, x, 6);
    if (title) Text_AppendFormatString(output, title);
    if (!(*(unsigned short *)(self + 0x438) & 2)) {
        short revealed = (short)(*(short *)(self + 0x448) - 12);
        short remaining = (short)(160 - revealed);
        if (revealed > 0 && remaining > 0) {
            TextMarkup_AppendSDRCTag(output, 1, revealed, 1, remaining, 22);
        } else if (revealed <= 0) {
            TextMarkup_AppendSDRCTag(output, 1, 1, 1, 158, 22);
        }
    }
    *(unsigned short *)(self + 0x438) &= ~2;
}
