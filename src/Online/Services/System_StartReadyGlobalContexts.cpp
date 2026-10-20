#include <globaldefs.h>
ARM
extern "C" void System_SwitchGlobalProcessorContext();
extern "C" void System_MarkGlobalContextReadyAndSwitch();
extern "C" int Ov031_IsGlobalModeTwoOrThree();
extern "C" void YssdClient_SetError(int,int);
// Original data: arm9/ov031 @ 0x224e590; symbol: data_ov031_0224e590.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" int *YssdSessionTryDestroy_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x022111E0; symbol: func_ov031_022111e0; size: 0x8C.
extern "C" int System_StartReadyGlobalContexts() {
    if (!YssdSessionTryDestroy_UnknownRoleZeroInitializedStorage) {
        YssdClient_SetError(9, -2);
        return 0;
    }
    if (Ov031_IsGlobalModeTwoOrThree()) return 0;
    if (!YssdSessionTryDestroy_UnknownRoleZeroInitializedStorage[1] && !YssdSessionTryDestroy_UnknownRoleZeroInitializedStorage[15]) {
        YssdClient_SetError(9, -2);
        return 0;
    }
    System_SwitchGlobalProcessorContext();
    System_MarkGlobalContextReadyAndSwitch();
    YssdSessionTryDestroy_UnknownRoleZeroInitializedStorage[0] = 2;
    return 1;
}
