#include <globaldefs.h>
ARM
extern "C" void *GameResources_GetInstance(void);
extern "C" int Combat_DispatchSelectionProcedure(void *, void *, int, int *);
extern "C" void Field_UpdateCombatantAppearanceFlags(int, int, int, int);
// Original: arm9/ov025 @ 0x021E8084; symbol: func_ov025_021e8084; size: 0x54.
extern "C" int DispatchSelectionAndNotifyResource(void *unused0, void *action, void *unused2, void *context) {
    int output[4];
    void *resources = GameResources_GetInstance();
    if (Combat_DispatchSelectionProcedure(context, action, 7, output))
        Field_UpdateCombatantAppearanceFlags((int)resources, 1, output[0], 4);
    return 1;
}
