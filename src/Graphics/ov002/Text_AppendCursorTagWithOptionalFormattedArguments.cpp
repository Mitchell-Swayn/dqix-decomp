#include <globaldefs.h>
ARM
extern "C" int AppendFiveFormattedArguments(char *, int, int, int, int, int);
extern "C" int TextMarkup_AppendCursorTag(char *, int);
// Original: arm9/ov002 @ 0x02160190; symbol: func_ov002_02160190; size: 0x50.
extern "C" void Text_AppendCursorTagWithOptionalFormattedArguments(void *base, char *out, int includeArguments) {
    if (includeArguments) {
        char *cursor = (char *)base + 0x1C00;
        int value = *(short *)(cursor + 6);
        AppendFiveFormattedArguments(out, value, 8, 5, 5, 5);
    }
    char *cursor = (char *)base + 0x1C00;
    int value = *(short *)(cursor + 6);
    TextMarkup_AppendCursorTag(out, value);
}
