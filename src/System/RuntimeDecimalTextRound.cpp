#include "System/RuntimeDecimal.h"

#pragma optimize_for_size off

// Unlike the arithmetic helpers, the formatter stores ASCII digits here.
extern "C" void func_02002b90(RuntimeDecimal* value, int length)
{
    if (length < 0) {
zero:
        value->exponent = 0;
        value->length = 1;
        value->digits[0] = '0';
        return;
    }
    int oldLength = value->length;
    if (length >= oldLength)
        return;
    // View the whole record: a half tie at length zero reads offset 4 (the
    // original length byte) for parity, as the original routine does.
    char* start = (char*)value + 5;
    char* cursor = start + length + 1;
    char digit = *--cursor - '0';
    int carry;
    if (digit == 5) {
        char* end = start + oldLength;
        do {
            --end;
            if (end <= cursor)
                break;
        } while (*end == '0');
        carry = end == cursor ? cursor[-1] & 1 : 1;
    } else {
        carry = digit > 5;
    }
    if (length != 0) {
        do {
            digit = (*--cursor - '0') + carry;
            carry = digit > 9;
            if (carry || digit == 0) {
                --length;
            } else {
                *cursor = digit + '0';
                break;
            }
        } while (length != 0);
    }
    if (carry) {
        ++value->exponent;
        value->length = 1;
        value->digits[0] = '1';
        return;
    }
    if (length == 0)
        goto zero;
    value->length = length;
}
