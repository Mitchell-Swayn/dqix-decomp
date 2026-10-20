#include <globaldefs.h>
ARM
extern "C" void *Graphics_UpdateSelectedResourceBranchesAndReleaseReadyBuffer(void *);
// Original: arm9/ov017 @ 0x021B8438; symbol: func_ov017_021b8438; size: 0x18.
extern "C" void FieldBattle_UpdateSceneResourceBranches(void *object) {
    void *value = *(void **)((unsigned char *)object + 0x6AC);
    if (value == 0)
        return;
    Graphics_UpdateSelectedResourceBranchesAndReleaseReadyBuffer(value);
}
