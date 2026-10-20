#include <globaldefs.h>
ARM
#pragma optimization_level 4

// Original: arm9/ov001 @ 0x021641E0; symbol: func_ov001_021641e0; size: 0x34.
// Stores type and, for types 2 or 6, the payload and nonzero count.
extern "C" int Event_BindActorPoolReference(unsigned int* object, unsigned int type, unsigned int payload, unsigned int count)
{
    if (!count) return 0;
    object[0] = type;
    switch (type) {
    case 2:
    case 6:
        object[1] = payload;
        object[3] = count;
        return 1;
    default:
        return 0;
    }
}
