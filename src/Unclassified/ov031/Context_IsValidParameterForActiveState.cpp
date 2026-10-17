#include <globaldefs.h>
ARM
extern "C" unsigned data_ov031_0224e590;
// Original: arm9/ov031 @ 0x02211484; symbol: func_ov031_02211484; size: 0x78.
extern "C" int Context_IsValidParameterForActiveState(int wideMode, unsigned value) {
    volatile unsigned* global = &data_ov031_0224e590;
    void* state = (void*)*global;
    if (state == 0) return 0;
    if (*(unsigned*)state != 2) return 0;
    if (*(unsigned*)((char*)state + 0x10) != 0) return 0;
    if (wideMode) {
        if (value < 1 || value > 0xff) return 0;
    } else {
        if (value < 1 || value > 0xf) return 0;
    }
    return 1;
}
