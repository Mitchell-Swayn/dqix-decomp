#include <globaldefs.h>
ARM
extern "C" void *GameResources_GetInstance(void);
// Original: arm9/ov001 @ 0x0215FEF4; symbol: func_ov001_0215fef4; size: 0x1C.
extern "C" int Resource_ClearGameResourcesWord3630(void) {
    *(int *)((char *)GameResources_GetInstance() + 0x3630) = 0;
    return 1;
}
