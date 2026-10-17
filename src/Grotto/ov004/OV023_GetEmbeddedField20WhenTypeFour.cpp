#include <globaldefs.h>
ARM
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, unsigned);
extern "C" unsigned OV023_ReadHalfwordField04(void*);
extern "C" void* OV023_GetEmbeddedField20(void*);
extern "C" int ScaleTypeTwelveCoordinatePair(void*);
// Original: arm9/ov004 @ 0x02168B08; symbol: func_ov004_02168b08; size: 0x3C.
extern "C" void* OV023_GetEmbeddedField20WhenTypeFour(void* self, unsigned value) {
    void* state = func_ov011_021849c8(self);
    void* result = func_ov023_021f6880(state, value);
    if (result != 0 && OV023_ReadHalfwordField04(result) == 4)
        return OV023_GetEmbeddedField20(result);
    return 0;
}
