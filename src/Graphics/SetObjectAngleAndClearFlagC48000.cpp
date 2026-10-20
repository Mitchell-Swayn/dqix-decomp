#include "Graphics/Vector.h"

extern "C" void Object3D_SetNormalizedAngleAndUpdatePosition(void*);
// Original: arm9/main @ 0x02033834; symbol: func_02033834; size: 0x40.
extern "C" void SetObjectAngleAndClearFlagC48000(void* object, int angle)
{
    unsigned char* bytes = (unsigned char*)object;
    if (bytes[0xbe] == 4 || bytes[0xbe] == 3) {
        Object3D_SetNormalizedAngleAndUpdatePosition(object);
    } else {
        *(short*)(bytes + 0xae) = (short)fix32ReduceAngle0To2Pi(angle);
    }
    *(unsigned short*)(bytes + 0xc4) &= ~0x8000;
}
