#include <globaldefs.h>
ARM
#pragma optimization_level 4
// Original data: arm9/ov031 @ 0x2249114; symbol: data_ov031_02249114.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 01020304.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char ConfigureTransformFromSharedSignedSelector_UnknownRoleInitializedBytes[];
// Original data: arm9/ov031 @ 0x2290cc8; symbol: data_ov031_02290cc8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char SystemConfigureSecondaryDisplayMode_UnknownRoleZeroInitializedStorage[];
extern "C" void WfcUtility_QueueBackgroundPaletteBankCopy(unsigned,unsigned,unsigned);
struct FourCoordinateBytes { unsigned char a,b,c,d; };
// Original: arm9/ov031 @ 0x022339A8; symbol: func_ov031_022339a8; size: 0x58.
// Signed selector must index the copied four-byte table; valid range is caller-owned.
extern "C" void ConfigureTransformFromSharedSignedSelector() {
 FourCoordinateBytes bytes=*(FourCoordinateBytes*)ConfigureTransformFromSharedSignedSelector_UnknownRoleInitializedBytes;
 unsigned char* table=(unsigned char*)&bytes;
 unsigned selected=table[*(signed char*)(SystemConfigureSecondaryDisplayMode_UnknownRoleZeroInitializedStorage+1)];
 WfcUtility_QueueBackgroundPaletteBankCopy(*(unsigned*)(SystemConfigureSecondaryDisplayMode_UnknownRoleZeroInitializedStorage+4),selected,selected);
}
