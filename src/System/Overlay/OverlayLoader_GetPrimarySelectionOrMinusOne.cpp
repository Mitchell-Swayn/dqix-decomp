#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original data: arm9/main @ 0x2109da4; symbol: data_02109da4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2109dae; symbol: data_02109dae.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 10 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern volatile unsigned char OverlayLoaderPushPrimarySelection_UnknownRoleZeroInitializedStorage;extern signed char OverlayLoaderPushPrimarySelection_UnknownRoleZeroInitializedStorage_Variant2[];
// Original: arm9/main @ 0x020A1EB0; symbol: func_020a1eb0; size: 0x2C.
int OverlayLoader_GetPrimarySelectionOrMinusOne(){int v;if(OverlayLoaderPushPrimarySelection_UnknownRoleZeroInitializedStorage!=0)v=OverlayLoaderPushPrimarySelection_UnknownRoleZeroInitializedStorage_Variant2[OverlayLoaderPushPrimarySelection_UnknownRoleZeroInitializedStorage-1];else v=-1;return v;}
}
