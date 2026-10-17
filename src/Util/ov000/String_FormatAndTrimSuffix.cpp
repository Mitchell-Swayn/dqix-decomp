#include <globaldefs.h>
ARM

extern "C" int sprintf(char *, const char *, ...);
extern "C" unsigned int String_CountBytesUntilTerminator(const signed char *);

// Original: arm9/ov000 @ 0x0217AA08; symbol: func_ov000_0217aa08; size: 0x70.
extern "C" void String_FormatAndTrimSuffix(const char *format, char *output) {
    if (format == 0 || output == 0) {
        return;
    }
    if (*format == 0) {
        return;
    }
    sprintf(output, format);
    int length = (int)String_CountBytesUntilTerminator((signed char *)output);
    if (length <= 0) {
        return;
    }
    signed char ch = output[length - 1];
    if (ch < 'A' || ch > 'Q') {
        return;
    }
    output[length - 1] = 0;
    if (output[length - 2] == ' ') {
        output[length - 2] = 0;
    }
}
