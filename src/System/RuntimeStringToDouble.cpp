#include "System/RuntimeStringInput.h"

#pragma optimize_for_size off

extern "C" double func_020042a8(int, RuntimeReadCharacter, RuntimeStringInputState*, int*, int*);
extern "C" double func_02008f3c(double);
extern int data_020f3390;

extern "C" double func_020054f4(const char* text, char** end)
{
    int consumed, overflow;
    RuntimeStringInputState input;
    input.cursor = text;
    input.endOfInput = 0;
    double value = func_020042a8(0x7fffffff, func_02003d58, &input, &consumed, &overflow);
    if (end) *end = (char*)text + consumed;
    double magnitude = func_02008f3c(value);
    if (overflow || (0.0 != value && (magnitude < 2.2250738585072014e-308 || magnitude > 1.7976931348623157e308)))
        data_020f3390 = 34;
    return value;
}
