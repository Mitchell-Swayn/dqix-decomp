#include "System/RuntimeStringInput.h"

#pragma optimize_for_size off

extern "C" unsigned int Runtime_ParseUnsignedIntegerFromCharacterCallback(int, int, RuntimeReadCharacter, RuntimeStringInputState*, int*, int*, int*);
// Original data: arm9/main @ 0x20f3390; symbol: data_020f3390.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern int Dsqrt_UnknownRoleZeroInitializedStorage;

// Original: arm9/main @ 0x020059CC; symbol: func_020059cc; size: 0xC8.
extern "C" int Runtime_ParseSignedStringInteger(const char* text, char** end, int base)
{
    int consumed, negative, overflow;
    RuntimeStringInputState input;
    input.cursor = text;
    input.endOfInput = 0;
    unsigned int value = Runtime_ParseUnsignedIntegerFromCharacterCallback(base, 0x7fffffff, RuntimeStringInput_ReadUnreadOrTestEnd, &input, &consumed, &negative, &overflow);
    if (end) *end = (char*)text + consumed;
    if (overflow || (!negative && value > 0x7fffffffu) || (negative && value > 0x80000000u)) {
        value = negative ? 0x80000000u : 0x7fffffffu;
        Dsqrt_UnknownRoleZeroInitializedStorage = 34;
        return value;
    }
    return negative ? -value : value;
}
