#include <globaldefs.h>
ARM
#pragma opt_propagation off
#pragma opt_dead_code off
struct State { unsigned char pad[100]; unsigned int value; };
// Original: arm9/main @ 0x0203CDD8; symbol: func_0203cdd8; size: 0x20.
extern "C" void ActorSprite_SetQuantizedTargetFacing(volatile State *p, unsigned int value) {
    p->value = value;
    unsigned low = value & 255;
    value &= ~255U;
    if (low >= (unsigned int)-128) value += 256;
    p->value = value;
}
