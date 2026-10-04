#pragma once

// Runtime conversion helpers limit the significand to 32 numeric digits.
struct RuntimeDecimal {
    unsigned char sign;
    unsigned char padding;
    short exponent;
    unsigned char length;
    unsigned char digits[32];
};

extern "C" int func_020095b0(RuntimeDecimal*, int);
extern "C" void func_0200961c(RuntimeDecimal*, int);
extern "C" void func_0200966c(RuntimeDecimal*, int);
