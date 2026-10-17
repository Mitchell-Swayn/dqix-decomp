#include <globaldefs.h>
#include "World/Object3D.h"
// Original: arm9/main @ 0x02041640; symbol: func_02041640; size: 0x14.
extern "C" void Object3D_SetAndRememberNamedAnimation(Object3D* self, const char* animName)
{
    self->MaybeSetRegularAnimation(*(const char**)((char*)self + 0x2f4) = animName, 0);
}
