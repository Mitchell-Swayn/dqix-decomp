#pragma thumb off
#pragma optimize_for_size off
struct PrintIntegerFormat {
    unsigned char padding, sign, precisionSpecified, alternate;
    unsigned char length, conversion;
    unsigned short reserved;
    int width, precision;
};
// Original: arm9/main @ 0x0200216C; symbol: func_0200216c; size: 0x24C.
// MSL long2str: write a formatted integer backward from the supplied buffer end.
extern "C" char* long2str(long number, char* end, PrintIntegerFormat format)
{
    unsigned int base;
    char* buffer = end;
    int negative = 0;
    int count = 0;
    int precision = format.precision;
    *--buffer = 0;
    int width = format.width;
    int conversion = format.conversion;
    int sign = format.sign;
    if (!number && !precision && (!format.alternate || conversion != 'o'))
        return buffer;
    switch (conversion) {
    case 'd':
    case 'i':
        base = 10;
        if (number < 0) {
            if (number != (long)0x80000000u) number = -number;
            negative = 1;
        }
        break;
    case 'u':
        base = 10;
        sign = 0;
        break;
    case 'o':
        base = 8;
        sign = 0;
        break;
    case 'x':
    case 'X':
        base = 16;
        sign = 0;
        break;
    }
    do {
        int digit = (unsigned long)number % base;
        number = (unsigned long)number / base;
        if (digit < 10) digit += '0';
        else if (conversion == 'x') digit += 'a' - 10;
        else digit += 'A' - 10;
        *--buffer = digit;
        ++count;
    } while (number);
    if (base == 8 && format.alternate && *buffer != '0') {
        *--buffer = '0';
        ++count;
    }
    if (format.padding == 2) {
        precision = width;
        if (negative || sign) --precision;
        if (base == 16 && format.alternate) precision -= 2;
    }
    if (precision + (end - buffer) > 509) return 0;
    if (count < precision) {
        do {
            *--buffer = '0';
            ++count;
        } while (count < precision);
    }
    if (base == 16 && format.alternate) {
        *--buffer = conversion;
        *--buffer = '0';
    }
    if (negative) *--buffer = '-';
    else if (sign == 1) *--buffer = '+';
    else if (sign == 2) *--buffer = ' ';
    return buffer;
}
