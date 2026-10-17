#include <globaldefs.h>
#pragma always_inline on
#pragma optimize_for_size off
extern "C" const unsigned short data_020e69ac[];
// printf conversion state: byte flags and length/conversion precede width/precision.
struct FormatFields {
    unsigned char padding, sign, precisionSpecified, alternate;
    unsigned char length, conversion;
    unsigned short reserved;
    int width, precision;
};
typedef FormatFields FormatConversion;
struct ConversionWords { unsigned int words[4]; };
static inline int IsDecimal(int c) {
    return c < 0 || c >= 128 ? 0 : data_020e69ac[c] & 8;
}
// Original: arm9/main @ 0x02001BDC; symbol: func_02001bdc; size: 0x590.
extern "C" const char* Runtime_ParsePrintfConversion(const char* format, int** arguments, FormatConversion* output) {
    FormatConversion spec;
    int c = format[1];
    const char* cursor = format + 1;
    spec.padding = 1;
    spec.sign = 0;
    spec.precisionSpecified = 0;
    spec.alternate = 0;
    spec.length = 0;
    spec.width = 0;
    spec.precision = 0;
    if (c == '%') {
        spec.conversion = c;
        *(ConversionWords*)output = *(ConversionWords*)&spec;
        return cursor + 1;
    }
    for (;;) {
        bool flag = true;
        switch(c) {
        case '-': spec.padding = 0; break;
        case '+': spec.sign = 1; break;
        case ' ': if (spec.sign != 1) spec.sign = 2; break;
        case '#': spec.alternate = 1; break;
        case '0': if (spec.padding != 0) spec.padding = 2; break;
        default: flag = false; break;
        }
        if (!flag) break;
        c = *++cursor;
    }
    if (c == '*') {
        ++*arguments;
        int width = (*arguments)[-1];
        spec.width = width;
        if (width < 0) {
            spec.padding = 0;
            spec.width = -width;
        }
        c = *++cursor;
    } else {
        while (IsDecimal(c)) {
            spec.width = spec.width * 10 + (c - '0');
            c = *++cursor;
        }
    }
    if (spec.width > 509) {
        spec.conversion = 255;
        *(ConversionWords*)output = *(ConversionWords*)&spec;
        return cursor + 1;
    }
    if (c == '.') {
        c = *++cursor;
        spec.precisionSpecified = 1;
        if (c == '*') {
            ++*arguments;
            spec.precision = (*arguments)[-1];
            c = *++cursor;
            if (spec.precision < 0) spec.precisionSpecified = 0;
        } else {
            while (IsDecimal(c)) {
                spec.precision = spec.precision * 10 + (c - '0');
                c = *++cursor;
            }
        }
    }
    bool length = true;
    switch(c) {
    case 'h':
        spec.length = 2;
        if (cursor[1] == 'h') { spec.length = 1; c = *++cursor; }
        break;
    case 'l':
        spec.length = 3;
        if (cursor[1] == 'l') { spec.length = 4; c = *++cursor; }
        break;
    case 'L': spec.length = 9; break;
    case 'j': spec.length = 6; break;
    case 't': spec.length = 8; break;
    case 'z': spec.length = 7; break;
    default: length = false; break;
    }
    if (length) c = *++cursor;
    spec.conversion = c;
    switch(c) {
    case 'd': case 'i': case 'o': case 'u': case 'x': case 'X':
        if (spec.length == 9) spec.conversion = 255;
        else if (!spec.precisionSpecified) spec.precision = 1;
        else if (spec.padding == 2) spec.padding = 1;
        break;
    case 'f': case 'F':
        if (spec.length == 2 || spec.length == 6 || spec.length == 7 || spec.length == 8 || spec.length == 4) spec.conversion = 255;
        else if (!spec.precisionSpecified) spec.precision = 6;
        break;
    case 'a': case 'A':
        if (!spec.precisionSpecified) spec.precision = 13;
        if (spec.length == 2 || spec.length == 6 || spec.length == 7 || spec.length == 8 || spec.length == 4 || spec.length == 1) spec.conversion = 255;
        break;
    case 'g': case 'G':
        if (spec.precision == 0) spec.precision = 1;
    case 'e': case 'E':
        if (spec.length == 2 || spec.length == 6 || spec.length == 7 || spec.length == 8 || spec.length == 4 || spec.length == 1) spec.conversion = 255;
        else if (!spec.precisionSpecified) spec.precision = 6;
        break;
    case 'p':
        spec.conversion = 'x'; spec.alternate = 1; spec.length = 3; spec.precision = 8; break;
    case 'c':
        if (spec.length == 3) spec.length = 5;
        else if (spec.precisionSpecified || spec.length != 0) spec.conversion = 255;
        break;
    case 's':
        if (spec.length == 3) spec.length = 5;
        else if (spec.length != 0) spec.conversion = 255;
        break;
    case 'n':
        if (spec.length == 9) spec.conversion = 255;
        break;
    default: spec.conversion = 255; break;
    }
    *(ConversionWords*)output = *(ConversionWords*)&spec;
    return cursor + 1;
}
