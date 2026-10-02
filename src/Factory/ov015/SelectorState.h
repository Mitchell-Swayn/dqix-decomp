#pragma once

// Layout recovered from the flag test and selector load in this accessor.
struct SelectorState {
    unsigned char unknown00[8];
    unsigned int flags;
    unsigned char unknown0c[0xa2];
    unsigned char selector;
};

extern "C" int func_ov015_0218bc9c(SelectorState* state);
