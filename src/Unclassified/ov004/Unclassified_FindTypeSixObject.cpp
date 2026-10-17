#include <globaldefs.h>
ARM
struct State;
extern "C" void *func_ov011_021849c8(State *self);
extern "C" void *func_ov023_021f6880(void *, unsigned int);
extern "C" unsigned int OV023_ReadHalfwordField04(void *);
extern "C" int ScaleTypeTwelveCoordinatePair(void *self);
// Original: arm9/ov004 @ 0x02156F6C; symbol: func_ov004_02156f6c; size: 0x34.
extern "C" void *Unclassified_FindTypeSixObject(State *self, unsigned int id) {
    void *current = func_ov011_021849c8(self);
    void *result = func_ov023_021f6880(current, id);
    if (result != 0 && OV023_ReadHalfwordField04(result) == 6) {
        return result;
    }
    return 0;
}
