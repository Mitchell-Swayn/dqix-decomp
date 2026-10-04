#pragma once

// The pinned runtime uses little-endian IEEE-754 binary32/binary64 storage.
// Bit initializers preserve its NaN payload as well as infinity values.
union RuntimeBinary32Constant {
    unsigned int bits;
    float value;
};
union RuntimeBinary64Constant {
    unsigned int words[2];
    double value;
};

extern RuntimeBinary32Constant data_020eecc4; // positive infinity
extern RuntimeBinary32Constant data_020eecc8; // NaN, payload bits all set
extern RuntimeBinary64Constant data_020eeccc; // positive infinity
typedef char RuntimeBinary32ConstantSizeCheck[sizeof(RuntimeBinary32Constant) == 4 ? 1 : -1];
typedef char RuntimeBinary64ConstantSizeCheck[sizeof(RuntimeBinary64Constant) == 8 ? 1 : -1];
