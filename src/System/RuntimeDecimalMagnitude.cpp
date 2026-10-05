#include "System/RuntimeDecimal.h"

#pragma optimize_for_size off

// Compare decimal magnitudes; the original helpers do not inspect sign.
extern "C" int func_02009d1c(RuntimeDecimal* left, RuntimeDecimal* right)
{
    if (!left->digits[0])
        return right->digits[0] == 0;
    if (!right->digits[0])
        return left->digits[0] == 0;
    if (left->exponent == right->exponent) {
        int index = 0;
        int count = left->length;
        if (count > right->length) count = right->length;
        if (count > 0) do {
            if (left->digits[index] != right->digits[index])
                return 0;
            ++index;
        } while (index < count);
        if (count == left->length) left = right;
        if (index < left->length) do {
            if (left->digits[index])
                return 0;
            ++index;
        } // Preserve the original length reload on each tail iteration.
        while (index < *(volatile unsigned char*)&left->length);
        return 1;
    }
    return 0;
}
extern "C" int func_02009dfc(RuntimeDecimal* left, RuntimeDecimal* right)
{
    if (!left->digits[0])
        return right->digits[0] != 0;
    if (!right->digits[0])
        return 0;
    if (left->exponent == right->exponent) {
        int index = 0;
        int count = left->length;
        if (count > right->length) count = right->length;
        if (count > 0) do {
            unsigned int rightDigit = right->digits[index];
            unsigned int leftDigit = left->digits[index];
            if (leftDigit < rightDigit)
                return 1;
            if (rightDigit < leftDigit)
                return 0;
            ++index;
        } while (index < count);
        if (count == left->length) {
            if (index < right->length) do {
                if (right->digits[index])
                    return 1;
                ++index;
            } // Preserve the original length reload on each tail iteration.
            while (index < *(volatile unsigned char*)&right->length);
        }
        return 0;
    }
    return left->exponent < right->exponent;
}

