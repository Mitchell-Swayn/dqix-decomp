#pragma once

// Runtime conversion helpers limit the significand to 32 numeric digits.
struct RuntimeDecimal {
    unsigned char sign;
    unsigned char padding;
    short exponent;
    unsigned char length;
    unsigned char digits[32];
};

extern "C" int Runtime_CompareDiscardedDecimalDigitsToHalf(RuntimeDecimal*, int);
extern "C" void __dorounddecup(RuntimeDecimal*, int);
extern "C" void RuntimeDecimalRound_RoundToDigitCount(RuntimeDecimal*, int);
