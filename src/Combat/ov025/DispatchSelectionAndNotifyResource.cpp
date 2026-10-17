#include <globaldefs.h>
ARM
extern "C" void *GameResources_GetInstance(void);
extern "C" int DispatchCombatSelectionProcedure(void *, void *, int, int *);
extern "C" void UpdateKeyedRecordByteFlags(int, int, int, int);
// Original: arm9/ov025 @ 0x021E8084; symbol: func_ov025_021e8084; size: 0x54.
extern "C" int DispatchSelectionAndNotifyResource(void *unused0, void *action, void *unused2, void *context) {
    int output[4];
    void *resources = GameResources_GetInstance();
    if (DispatchCombatSelectionProcedure(context, action, 7, output))
        UpdateKeyedRecordByteFlags((int)resources, 1, output[0], 4);
    return 1;
}
