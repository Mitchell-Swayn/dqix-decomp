#include "System/RuntimeStringInput.h"

#pragma optimize_for_size off

extern "C" double Runtime_ParseDoubleFromCharacterCallback(int, RuntimeReadCharacter, RuntimeStringInputState*, int*, int*);
extern "C" double Runtime_ComputeDoubleAbsoluteValue(double);
// Original data: arm9/main @ 0x20f3390; symbol: data_020f3390.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern int Dsqrt_UnknownRoleZeroInitializedStorage;

// Original: arm9/main @ 0x020054F4; symbol: func_020054f4; size: 0xE0.
extern "C" double Runtime_ParseStringAsDouble(const char* text, char** end)
{
    int consumed, overflow;
    RuntimeStringInputState input;
    input.cursor = text;
    input.endOfInput = 0;
    double value = Runtime_ParseDoubleFromCharacterCallback(0x7fffffff, RuntimeStringInput_ReadUnreadOrTestEnd, &input, &consumed, &overflow);
    if (end) *end = (char*)text + consumed;
    double magnitude = Runtime_ComputeDoubleAbsoluteValue(value);
    if (overflow || (0.0 != value && (magnitude < 2.2250738585072014e-308 || magnitude > 1.7976931348623157e308)))
        Dsqrt_UnknownRoleZeroInitializedStorage = 34;
    return value;
}
