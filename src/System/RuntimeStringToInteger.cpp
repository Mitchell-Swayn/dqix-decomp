#include "System/RuntimeStringInput.h"

#pragma optimize_for_size off

extern "C" unsigned int func_020055e4(int, int, RuntimeReadCharacter, RuntimeStringInputState*, int*, int*, int*);
extern int data_020f3390;

extern "C" int func_020059cc(const char* text, char** end, int base)
{
    int consumed, negative, overflow;
    RuntimeStringInputState input;
    input.cursor = text;
    input.endOfInput = 0;
    unsigned int value = func_020055e4(base, 0x7fffffff, func_02003d58, &input, &consumed, &negative, &overflow);
    if (end) *end = (char*)text + consumed;
    if (overflow || (!negative && value > 0x7fffffffu) || (negative && value > 0x80000000u)) {
        value = negative ? 0x80000000u : 0x7fffffffu;
        data_020f3390 = 34;
        return value;
    }
    return negative ? -value : value;
}
