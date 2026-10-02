#include "PatternState.h"

// The caller clears its output buffer first; this copies no terminating zero.
// Keep the signed-char assignment result: MWCC reloads the stored byte before
// deciding whether to advance the source, as in the original instructions.
extern "C" void func_ov012_021855f0(PatternState*, const char* input, char* output)
{
    char value;
    while ((value = *input) != 0) {
        if (value >= 'a' && value <= 'z') {
            value = *output = value - ('a' - 'A');
        } else {
            value = *output = value;
        }
        if (value != 0) {
            ++input;
        }
        ++output;
    }
}

extern "C" int func_ov012_02185634(PatternState*, const char* pattern,
                                    const char* input, unsigned int length,
                                    int positions)
{
    for (int i = 0; i < positions; ++i, ++input) {
        if (func_02001aec(pattern, input, length) == 0) {
            return 1;
        }
    }
    return 0;
}
