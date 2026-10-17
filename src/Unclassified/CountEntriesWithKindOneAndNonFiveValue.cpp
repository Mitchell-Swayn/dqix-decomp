#include <globaldefs.h>

// Original: arm9/main @ 0x02026ABC; symbol: func_02026abc; size: 0x50.
extern "C" unsigned char CountEntriesWithKindOneAndNonFiveValue(const unsigned char* state)
{
    unsigned char matches = 0;
    for (int i = 0; i < state[0x780]; ++i) {
        const unsigned char* entry = state + i * 0x1c;
        if (*reinterpret_cast<const unsigned short*>(entry + 0x78e) == 1 &&
            *reinterpret_cast<const unsigned short*>(entry + 0x78a) != 5) {
            ++matches;
        }
    }
    return matches;
}
