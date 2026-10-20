#include <globaldefs.h>
ARM
extern "C" void *Network_GetConnectionManager(void);
extern "C" unsigned int WaitForStateThreeThenProcessOwnerWithTimeout(void *);
extern "C" void *GameResources_GetInstance(void);
extern "C" void GameResources_ClearSecondaryFlags(void *, unsigned int);
extern "C" void GameResources_ClearPrimaryFlags(unsigned int *, unsigned int);
extern "C" void Field_QueueZoneTransitionWithInsertionPolicy(int, int, int, int);
// Original: arm9/ov003 @ 0x02170D38; symbol: func_ov003_02170d38; size: 0x50.
extern "C" void System_ResetConnectionResourceFlags(void) {
    WaitForStateThreeThenProcessOwnerWithTimeout(Network_GetConnectionManager());
    unsigned char *resources = (unsigned char *)GameResources_GetInstance();
    *(unsigned int *)(resources + 0x4000 + 0x494) = 0;
    resources = (unsigned char *)GameResources_GetInstance();
    GameResources_ClearSecondaryFlags(resources, 2);
    GameResources_ClearPrimaryFlags((unsigned int *)resources, 4);
    Field_QueueZoneTransitionWithInsertionPolicy(1, 0, 0, 0);
}
