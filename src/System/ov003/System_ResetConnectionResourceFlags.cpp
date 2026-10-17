#include <globaldefs.h>
ARM
extern "C" void *Object_GetGlobalConnectionState(void);
extern "C" unsigned int WaitForStateThreeThenProcessOwnerWithTimeout(void *);
extern "C" void *GameResources_GetInstance(void);
extern "C" void ClearWordAtOffset4MaskedBits(void *, unsigned int);
extern "C" void Flags_ClearWordMask(unsigned int *, unsigned int);
extern "C" void Resource_ResetAndInsertTypeThreeRecord(int, int, int, int);
// Original: arm9/ov003 @ 0x02170D38; symbol: func_ov003_02170d38; size: 0x50.
extern "C" void System_ResetConnectionResourceFlags(void) {
    WaitForStateThreeThenProcessOwnerWithTimeout(Object_GetGlobalConnectionState());
    unsigned char *resources = (unsigned char *)GameResources_GetInstance();
    *(unsigned int *)(resources + 0x4000 + 0x494) = 0;
    resources = (unsigned char *)GameResources_GetInstance();
    ClearWordAtOffset4MaskedBits(resources, 2);
    Flags_ClearWordMask((unsigned int *)resources, 4);
    Resource_ResetAndInsertTypeThreeRecord(1, 0, 0, 0);
}
