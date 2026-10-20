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

// Original data: arm9/main @ 0x20e6abc; symbol: data_020e6abc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000000000000000004003b8e23f.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern const RuntimeMathTables RuntimePowerEvaluateDoublePower_UnknownRoleInitializedBytes;
typedef char RuntimeMathTablesSizeCheck[sizeof(RuntimeMathTables) == 520 ? 1 : -1];
