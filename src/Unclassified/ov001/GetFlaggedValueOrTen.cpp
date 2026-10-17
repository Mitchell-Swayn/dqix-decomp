#include <globaldefs.h>
ARM
#include <Resource/GameResources.h>

// Original: arm9/ov001 @ 0x0215647C; symbol: func_ov001_0215647c; size: 0x34.
// Returns field 0xA, overridden with 10 by the object or resource flag.
extern "C" unsigned int GetFlaggedValueOrTen(unsigned char* object)
{
    if (object[0xfc]) return 10;
    if (((unsigned char*)GameResources_GetInstance())[0x42e2]) return 10;
    return *(unsigned short*)(object + 0xa);
}
