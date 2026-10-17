#include <globaldefs.h>
// Original: arm9/main @ 0x02083834; symbol: func_02083834; size: 0x38.
extern "C" void FillFirstNegativeSlotAmongEightHalfwords(unsigned char* state, int value)
{
    if (value < 0) return;
    for (int i = 0; i < 8; ++i) {
        unsigned char* entry = state + i * 2;
        entry += 0x400;
        short previous = *reinterpret_cast<volatile short*>(entry + 0x54);
        if (previous < 0) {
            *reinterpret_cast<volatile short*>(entry + 0x54) = static_cast<short>(value);
            return;
        }
    }
}
