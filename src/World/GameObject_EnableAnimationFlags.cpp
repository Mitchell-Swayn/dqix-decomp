#include "GameState/GameState.h"

// The target treats this pointer as a GameObject: Object3D begins at offset 0,
// and the extra byte at 0xe0 falls in its still-unknown tail fields.
// Original: arm9/main @ 0x02033FEC; symbol: func_02033fec; size: 0x20.
extern "C" void GameObject_EnableAnimationFlags(GameObject* object)
{
    object->obj3D_.EnableFlag(0x40000);
    ((unsigned char*)object)[0xe0] |= 2;
}
