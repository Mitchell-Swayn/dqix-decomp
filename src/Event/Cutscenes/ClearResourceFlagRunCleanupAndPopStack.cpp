#include <globaldefs.h>
ARM
extern "C" void *GameResources_GetInstance(void);
extern "C" void GameResources_ClearPrimaryFlags(unsigned int *, unsigned int);
extern "C" void StaffRoll_StopAndRestoreDisplay(void);
extern "C" void OverlayLoader_PopSecondarySelectionAndOptionallyRestoreOverlay(int);
// Original: arm9/ov001 @ 0x0216227C; symbol: func_ov001_0216227c; size: 0x24.
extern "C" int ClearResourceFlagRunCleanupAndPopStack(void) {
    GameResources_ClearPrimaryFlags((unsigned int *)GameResources_GetInstance(), 0x1000);
    StaffRoll_StopAndRestoreDisplay();
    OverlayLoader_PopSecondarySelectionAndOptionallyRestoreOverlay(1);
    return 1;
}
