#include "PatternState.h"

extern "C" int func_ov012_021859f4(PatternState*, const unsigned char* bytes,
                                    int count, int value)
{
    for (int i = 0; i < count; ++i, ++bytes) {
        if (*bytes == value) {
            return 1;
        }
    }
    return 0;
}
