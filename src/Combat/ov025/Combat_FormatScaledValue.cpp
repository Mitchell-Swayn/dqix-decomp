#include <globaldefs.h>
ARM
extern "C" const char *data_ov025_021ef520[];
extern "C" int sprintf(char *, const char *, ...);
// Original: arm9/ov025 @ 0x021E278C; symbol: func_ov025_021e278c; size: 0x3C.
extern "C" int Combat_FormatScaledValue(int value, char *buffer) {
    int quotient = value / 1000000;
    int remainder = value - quotient * 1000000;
    return sprintf(buffer, data_ov025_021ef520[quotient], remainder);
}
