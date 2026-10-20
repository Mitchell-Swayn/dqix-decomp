#include <globaldefs.h>
ARM
// Original: arm9/ov031:0222e09c; Stores the shared signed mode byte, dispatches arguments 7 or 14 for modes 0 or 1, then runs setup and installs the adjacent callback.
extern "C" int WfcUtility_GetDialogSelectionResult();
extern "C" void WfcUtility_PlaySequenceArchiveEntry(int);
extern "C" void CreateSharedDisplayResource();
extern "C" void WfcUtility_SetMainLoopCallback(void*);
extern "C" void WfcUtility_ApplyIpv4EditorResultOrResume();
// Original data: arm9/ov031 @ 0x2290c98; symbol: data_ov031_02290c98.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char* WfcUtilityReleaseIpv4Editor_UnknownRoleZeroInitializedStorage;
#define MODE_GLOBAL (*(volatile unsigned char**)&WfcUtilityReleaseIpv4Editor_UnknownRoleZeroInitializedStorage)
extern "C" void WfcUtility_OpenIpv4ConfirmationPrompt() {
    MODE_GLOBAL[0x15] = (unsigned char)WfcUtility_GetDialogSelectionResult();
    unsigned char mode = MODE_GLOBAL[0x15];
    switch (mode) {
    case 0: WfcUtility_PlaySequenceArchiveEntry(7); break;
    case 1: WfcUtility_PlaySequenceArchiveEntry(14); break;
    default: return;
    }
    CreateSharedDisplayResource();
    WfcUtility_SetMainLoopCallback((void*)WfcUtility_ApplyIpv4EditorResultOrResume);
}
