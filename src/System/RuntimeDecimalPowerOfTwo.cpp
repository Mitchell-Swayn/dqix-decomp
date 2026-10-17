#include "System/RuntimeDecimalPowers.h"
#include "System/RuntimeDecimal.h"
#pragma optimize_for_size off
// Copy the full 38-byte object representation, including its padding.
union RuntimeDecimalStorage { RuntimeDecimal decimal; unsigned short words[19]; };
extern "C" void Runtime_InitializeDecimalDigitsFromText(RuntimeDecimal*, const char*, short);
extern "C" void func_02009778(RuntimeDecimal*, const RuntimeDecimal*, const RuntimeDecimal*);
// Original: arm9/main @ 0x02009998; symbol: func_02009998; size: 0x384.
extern "C" void RuntimeDecimalPowerOfTwo_ComputeDecimalPowerOfTwo(RuntimeDecimal* result, int exponent)
{
    RuntimeDecimal half;
    RuntimeDecimalStorage saved;
    switch (exponent) {
    case -64:
        Runtime_InitializeDecimalDigitsFromText(result, gRuntimeDecimalPowers.powerN64, -20);
        return;
    case -53:
        Runtime_InitializeDecimalDigitsFromText(result, gRuntimeDecimalPowers.powerN53, -16);
        return;
    case -32:
        Runtime_InitializeDecimalDigitsFromText(result, gRuntimeDecimalPowers.powerN32, -10);
        return;
    case -16:
        Runtime_InitializeDecimalDigitsFromText(result, gRuntimeDecimalPowers.powerN16, -5);
        return;
    case -8:
        Runtime_InitializeDecimalDigitsFromText(result, gRuntimeDecimalPowers.powerN8, -3);
        return;
    case -7:
        Runtime_InitializeDecimalDigitsFromText(result, gRuntimeDecimalPowers.powerN7, -3);
        return;
    case -6:
        Runtime_InitializeDecimalDigitsFromText(result, gRuntimeDecimalPowers.powerN6, -2);
        return;
    case -5:
        Runtime_InitializeDecimalDigitsFromText(result, gRuntimeDecimalPowers.powerN5, -2);
        return;
    case -4:
        Runtime_InitializeDecimalDigitsFromText(result, gRuntimeDecimalPowers.powerN4, -2);
        return;
    case -3:
        Runtime_InitializeDecimalDigitsFromText(result, gRuntimeDecimalPowers.powerN3, -1);
        return;
    case -2:
        Runtime_InitializeDecimalDigitsFromText(result, gRuntimeDecimalPowers.powerN2, -1);
        return;
    case -1:
        Runtime_InitializeDecimalDigitsFromText(result, gRuntimeDecimalPowers.powerN1, -1);
        return;
    case 0:
        Runtime_InitializeDecimalDigitsFromText(result, gRuntimeDecimalPowers.power0, 0);
        return;
    case 1:
        Runtime_InitializeDecimalDigitsFromText(result, gRuntimeDecimalPowers.power1, 0);
        return;
    case 2:
        Runtime_InitializeDecimalDigitsFromText(result, gRuntimeDecimalPowers.power2, 0);
        return;
    case 3:
        Runtime_InitializeDecimalDigitsFromText(result, gRuntimeDecimalPowers.power3, 0);
        return;
    case 4:
        Runtime_InitializeDecimalDigitsFromText(result, gRuntimeDecimalPowers.power4, 1);
        return;
    case 5:
        Runtime_InitializeDecimalDigitsFromText(result, gRuntimeDecimalPowers.power5, 1);
        return;
    case 6:
        Runtime_InitializeDecimalDigitsFromText(result, gRuntimeDecimalPowers.power6, 1);
        return;
    case 7:
        Runtime_InitializeDecimalDigitsFromText(result, gRuntimeDecimalPowers.power7, 2);
        return;
    case 8:
        Runtime_InitializeDecimalDigitsFromText(result, gRuntimeDecimalPowers.power8, 2);
        return;
    }
    // Bias negative odd exponents before the arithmetic shift (division toward zero).
    RuntimeDecimalPowerOfTwo_ComputeDecimalPowerOfTwo(&half, (exponent + (int)(((unsigned int)exponent & 0x80000000) >> 31)) >> 1);
    func_02009778(result, &half, &half);
    if ((exponent & 1) == 0)
        return;
    saved = *(const RuntimeDecimalStorage*)result;
    if (exponent > 0)
        Runtime_InitializeDecimalDigitsFromText(&half, gRuntimeDecimalPowers.power1, 0);
    else
        Runtime_InitializeDecimalDigitsFromText(&half, gRuntimeDecimalPowers.powerN1, -1);
    func_02009778(result, &saved.decimal, &half);
}
