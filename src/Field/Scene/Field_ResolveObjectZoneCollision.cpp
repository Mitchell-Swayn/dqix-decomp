#include <globaldefs.h>
ARM
extern "C" void Field_ResolveObjectZoneCollisionWithMovement(void *, void *, int, int, int, int);
// Original: arm9/ov017 @ 0x02193428; symbol: func_ov017_02193428; size: 0x24.
extern "C" void Field_ResolveObjectZoneCollision(void *arg0, void *arg1) {
    Field_ResolveObjectZoneCollisionWithMovement(arg0, arg1, 0, 0, 0, 0);
}
