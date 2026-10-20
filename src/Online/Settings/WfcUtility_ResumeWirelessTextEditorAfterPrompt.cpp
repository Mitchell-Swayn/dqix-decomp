#include <globaldefs.h>
ARM
extern "C" int WfcUtility_IsDialogActive(void);
extern "C" void WfcUtility_SetMainLoopCallback(void*);
// Original data: arm9/ov031 @ 0x2290c94; symbol: data_ov031_02290c94.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int WfcUtilityReleaseWirelessTextEditor_UnknownRoleZeroInitializedStorage;
extern "C" void WfcUtility_ArmWirelessTextEditorInput(void);
// Original: arm9/ov031 @ 0x0222D6DC; symbol: func_ov031_0222d6dc; size: 0x44.
extern "C" void WfcUtility_ResumeWirelessTextEditorAfterPrompt(void) {
    if (WfcUtility_IsDialogActive()) return;
    unsigned int* object = *(unsigned int**)&WfcUtilityReleaseWirelessTextEditor_UnknownRoleZeroInitializedStorage;
    unsigned int* field = *(unsigned int**)((char*)object + 4);
    *field &= 0xc1fffcff;
    WfcUtility_SetMainLoopCallback((void*)WfcUtility_ArmWirelessTextEditorInput);
}
