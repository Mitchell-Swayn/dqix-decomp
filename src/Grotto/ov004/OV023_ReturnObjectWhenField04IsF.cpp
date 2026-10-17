#include <globaldefs.h>
ARM
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, unsigned);
extern "C" unsigned OV023_ReadHalfwordField04(void*);
extern "C" int ScaleTypeTwelveCoordinatePair(void*);
// Original: arm9/ov004 @ 0x02168A38; symbol: func_ov004_02168a38; size: 0x34.
extern "C" void* OV023_ReturnObjectWhenField04IsF(void* self, unsigned value) {
    void* state = func_ov011_021849c8(self);
    void* result = func_ov023_021f6880(state, value);
    if (result != 0) {
        if (OV023_ReadHalfwordField04(result) == 0xf) return result;
    }
    return 0;
}
