#include "System/RuntimeDecimal.h"
#pragma optimize_for_size off
extern "C" void func_0200a180(RuntimeDecimal*, double);
// The first format halfword is not interpreted by this conversion entry.
struct RuntimeDecimalFormat { unsigned short reserved; short precision; };
extern "C" void func_0200a300(const RuntimeDecimalFormat* format, double value, RuntimeDecimal* result)
{
    int precision = format->precision;
    func_0200a180(result, value);
    if (result->digits[0] > 9)
        return;
    if (precision > 32)
        precision = 32;
    func_0200966c(result, precision);
    if (result->length < precision) {
        do {
            result->digits[result->length++] = 0;
        } while (result->length < precision);
    }
    result->exponent -= result->length - 1;
    int i = 0;
    if (i < result->length) {
        do {
            unsigned char digit = result->digits[i];
            result->digits[i++] = digit + '0';
        } while (i < result->length);
    }
}
