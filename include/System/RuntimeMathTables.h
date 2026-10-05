#pragma once

// Shared power/logarithm and pi/2 argument-reduction constants.
struct RuntimeMathTables {
    double powerLog2High[2];
    double powerBases[2];
    double powerLog2Low[2];
    unsigned int piOver2MultipleHighWords[32];
    unsigned int twoOverPiDigits[66];
    int reductionTerms[4];
    double piOver2Pieces[8];
};

extern const RuntimeMathTables data_020e6abc;
typedef char RuntimeMathTablesSizeCheck[sizeof(RuntimeMathTables) == 520 ? 1 : -1];
