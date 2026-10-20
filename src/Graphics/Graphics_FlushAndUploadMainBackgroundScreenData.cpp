#include <globaldefs.h>
#include <System/Cache.h>
#include <System/LoadToVRAM.h>
extern "C" {
// Original data: arm9/main @ 0x20fe9cc; symbol: data_020fe9cc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1536 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char DebugTextWriteTileString_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x0202ADF0; symbol: func_0202adf0; size: 0x28.
void Graphics_FlushAndUploadMainBackgroundScreenData(){CleanInvalidateCacheRange(DebugTextWriteTileString_UnknownRoleZeroInitializedStorage,0x600);LoadToMainBG1ScreenData(DebugTextWriteTileString_UnknownRoleZeroInitializedStorage,0,0x600);}
}
