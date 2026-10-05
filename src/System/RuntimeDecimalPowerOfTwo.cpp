#include "System/RuntimeDecimalPowers.h"
#include "System/RuntimeDecimal.h"
#pragma optimize_for_size off
// Copy the full 38-byte object representation, including its padding.
union RuntimeDecimalStorage { RuntimeDecimal decimal; unsigned short words[19]; };
extern "C" void func_020098fc(RuntimeDecimal*, const char*, short);
extern "C" void func_02009778(RuntimeDecimal*, const RuntimeDecimal*, const RuntimeDecimal*);
extern "C" void func_02009998(RuntimeDecimal* result, int exponent)
{
    RuntimeDecimal half;
    RuntimeDecimalStorage saved;
    switch (exponent) {
    case -64:
        func_020098fc(result, gRuntimeDecimalPowers.powerN64, -20);
        return;
    case -53:
        func_020098fc(result, gRuntimeDecimalPowers.powerN53, -16);
        return;
    case -32:
        func_020098fc(result, gRuntimeDecimalPowers.powerN32, -10);
        return;
    case -16:
        func_020098fc(result, gRuntimeDecimalPowers.powerN16, -5);
        return;
    case -8:
        func_020098fc(result, gRuntimeDecimalPowers.powerN8, -3);
        return;
    case -7:
        func_020098fc(result, gRuntimeDecimalPowers.powerN7, -3);
        return;
    case -6:
        func_020098fc(result, gRuntimeDecimalPowers.powerN6, -2);
        return;
    case -5:
        func_020098fc(result, gRuntimeDecimalPowers.powerN5, -2);
        return;
    case -4:
        func_020098fc(result, gRuntimeDecimalPowers.powerN4, -2);
        return;
    case -3:
        func_020098fc(result, gRuntimeDecimalPowers.powerN3, -1);
        return;
    case -2:
        func_020098fc(result, gRuntimeDecimalPowers.powerN2, -1);
        return;
    case -1:
        func_020098fc(result, gRuntimeDecimalPowers.powerN1, -1);
        return;
    case 0:
        func_020098fc(result, gRuntimeDecimalPowers.power0, 0);
        return;
    case 1:
        func_020098fc(result, gRuntimeDecimalPowers.power1, 0);
        return;
    case 2:
        func_020098fc(result, gRuntimeDecimalPowers.power2, 0);
        return;
    case 3:
        func_020098fc(result, gRuntimeDecimalPowers.power3, 0);
        return;
    case 4:
        func_020098fc(result, gRuntimeDecimalPowers.power4, 1);
        return;
    case 5:
        func_020098fc(result, gRuntimeDecimalPowers.power5, 1);
        return;
    case 6:
        func_020098fc(result, gRuntimeDecimalPowers.power6, 1);
        return;
    case 7:
        func_020098fc(result, gRuntimeDecimalPowers.power7, 2);
        return;
    case 8:
        func_020098fc(result, gRuntimeDecimalPowers.power8, 2);
        return;
    }
    // Bias negative odd exponents before the arithmetic shift (division toward zero).
    func_02009998(&half, (exponent + (int)(((unsigned int)exponent & 0x80000000) >> 31)) >> 1);
    func_02009778(result, &half, &half);
    if ((exponent & 1) == 0)
        return;
    saved = *(const RuntimeDecimalStorage*)result;
    if (exponent > 0)
        func_020098fc(&half, gRuntimeDecimalPowers.power1, 0);
    else
        func_020098fc(&half, gRuntimeDecimalPowers.powerN1, -1);
    func_02009778(result, &saved.decimal, &half);
}
