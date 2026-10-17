#include <globaldefs.h>
ARM
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void**, unsigned short);
extern "C" unsigned OV023_ReadHalfwordField04(void*);
// Original: arm9/ov023 @ 0x021F9CB8; symbol: func_ov023_021f9cb8; size: 0x5C.
extern "C" void* OV023_FindTypeSixFromTypeEight(unsigned unused, void* stateObject, void* candidate) {
    if (candidate == 0) return 0;
    if (OV023_ReadHalfwordField04(candidate) != 8) return 0;
    unsigned short value = *(unsigned short*)((char*)candidate + 0x34);
    void* state = func_ov011_021849c8(stateObject);
    void* result = func_ov023_021f6880((void**)state, value);
    if (result == 0) return 0;
    if (OV023_ReadHalfwordField04(result) != 6) return 0;
    return result;
}
