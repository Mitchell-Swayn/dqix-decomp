#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x0215991C; symbol: func_ov000_0215991c; size: 0x18.
extern "C" unsigned Combat_HasTimedAttackModifier(void *object) {
    unsigned *state = *(unsigned **)((char *)object + 0x138);
    return (*(unsigned *)((char *)state + 0x14) & 0x400) != 0;
}
