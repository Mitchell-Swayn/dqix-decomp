#include <globaldefs.h>
ARM
extern "C" void *Zone3D_GetMainInstance();
extern "C" void *GameResources_GetInstance();
extern "C" void GameResources_ClearSecondaryFlags(int, unsigned int);
// Original: arm9/ov017 @ 0x021B2AD8; symbol: func_ov017_021b2ad8; size: 0x3C.
extern "C" int FieldScreen_WaitForZoneReload(void *self) {
    if (*(unsigned int *)((char *)Zone3D_GetMainInstance() + 0x424) != 0)
        return (int)*(unsigned int *)((char *)self + 8);
    GameResources_ClearSecondaryFlags((int)GameResources_GetInstance(), 2);
    *(unsigned int *)((char *)self + 0x38) &= ~1;
    return 3;
}
