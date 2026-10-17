#include "System/RuntimeStringInput.h"

#pragma optimize_for_size off

extern "C" double func_020042a8(int, RuntimeReadCharacter, RuntimeStringInputState*, int*, int*);
extern "C" double Runtime_ComputeDoubleAbsoluteValue(double);
extern int data_020f3390;

// Original: arm9/main @ 0x020054F4; symbol: func_020054f4; size: 0xE0.
extern "C" double Runtime_ParseStringAsDouble(const char* text, char** end)
{
    int consumed, overflow;
    RuntimeStringInputState input;
    input.cursor = text;
    input.endOfInput = 0;
    double value = func_020042a8(0x7fffffff, RuntimeStringInput_ReadUnreadOrTestEnd, &input, &consumed, &overflow);
    if (end) *end = (char*)text + consumed;
    double magnitude = Runtime_ComputeDoubleAbsoluteValue(value);
    if (overflow || (0.0 != value && (magnitude < 2.2250738585072014e-308 || magnitude > 1.7976931348623157e308)))
        data_020f3390 = 34;
    return value;
}
