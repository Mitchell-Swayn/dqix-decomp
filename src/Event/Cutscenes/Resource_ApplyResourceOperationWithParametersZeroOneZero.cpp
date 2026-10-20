#include <globaldefs.h>
ARM
extern "C" void *GameResources_GetInstance(void);
extern "C" void Field_RequestRecoveryZoneTransition(void *, int, int, int);
// Original: arm9/ov001 @ 0x02162468; symbol: Resource_ApplyResourceOperationWithParametersZeroOneZero; size: 0x20.
// Invokes the resource routine with the singleton and parameters 0, 1, 0, then returns one.
extern "C" int Resource_ApplyResourceOperationWithParametersZeroOneZero(void) {
    void *resources = GameResources_GetInstance();
    Field_RequestRecoveryZoneTransition(resources, 0, 1, 0);
    return 1;
}
