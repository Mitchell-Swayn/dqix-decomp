#pragma once

struct RuntimeDecimalPowers {
    char powerN64[48];
    char powerN53[40];
    char powerN32[24];
    char powerN16[16];
    char powerN8[8];
    char powerN7[8];
    char powerN6[8];
    char powerN5[8];
    char powerN4[4];
    char powerN3[4];
    char powerN2[4];
    char powerN1[4];
    char power0[4];
    char power1[4];
    char power2[4];
    char power3[4];
    char power4[4];
    char power5[4];
    char power6[4];
    char power7[4];
    char power8[4];
};

extern RuntimeDecimalPowers gRuntimeDecimalPowers;
