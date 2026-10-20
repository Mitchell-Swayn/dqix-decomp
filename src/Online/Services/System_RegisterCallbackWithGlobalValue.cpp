#include <globaldefs.h>
ARM
extern "C" int System_CreateAndSwitchProcessorContextForCallback(void (*)(void));
// Original data: arm9/ov031 @ 0x2290da0; symbol: data_ov031_02290da0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int DlcDownloadShutdownClient_UnknownRoleZeroInitializedStorage[];
extern "C" void DlcDownload_ShutdownClient(void);
// Original: arm9/ov031 @ 0x0223E8AC; symbol: func_ov031_0223e8ac; size: 0x28.
extern "C" int System_RegisterCallbackWithGlobalValue(unsigned int value) { DlcDownloadShutdownClient_UnknownRoleZeroInitializedStorage[5] = 0; DlcDownloadShutdownClient_UnknownRoleZeroInitializedStorage[0] = value; return System_CreateAndSwitchProcessorContextForCallback(DlcDownload_ShutdownClient); }
