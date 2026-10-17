#include <globaldefs.h>
ARM
#pragma optimization_level 4
struct State;
extern "C" void *func_ov011_021849c8(State *self);
extern "C" void *func_ov023_021f6880(void *, unsigned int);
extern "C" unsigned int OV023_ReadHalfwordField04(void *);
// Original: arm9/ov023 @ 0x021F6378; symbol: func_ov023_021f6378; size: 0x34.
extern "C" unsigned int Object_GetField38ForMatchingTypeEightByKey(State *self, unsigned int id) {
    void *current = func_ov011_021849c8(self);
    void *result = func_ov023_021f6880(current, id);
    if (result == 0) return 0;
    unsigned int type = OV023_ReadHalfwordField04(result);
    return type != 8 ? 0 : *(unsigned short *)((unsigned char *)result + 0x38);
}
