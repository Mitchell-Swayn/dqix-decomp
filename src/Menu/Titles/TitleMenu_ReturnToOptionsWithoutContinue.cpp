#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(void*, unsigned int);
// Original data: arm9/ov004 @ 0x2171034; symbol: data_ov004_02171034.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned char InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov004 @ 0x0216DF7C; symbol: SetOverlayConfigByte3ToFiveAndStateValue301; size: 0x24.
// Writes byte 5 to overlay data offset 3 and sends state value 0x12D through the state setter.
extern "C" int TitleMenu_ReturnToOptionsWithoutContinue(void* self) { InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage[3] = 5; Menu_QueueScriptEntry(self, 0x12d); return 0; }
