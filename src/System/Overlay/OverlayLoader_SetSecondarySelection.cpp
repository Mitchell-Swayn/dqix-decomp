#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2109da4; symbol: data_02109da4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2109da6; symbol: data_02109da6.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" volatile unsigned char OverlayLoaderPushPrimarySelection_UnknownRoleZeroInitializedStorage[]; extern "C" unsigned char OverlayLoaderSetSecondarySelection_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020A1FD4; symbol: func_020a1fd4; size: 0x28.
 extern "C" void OverlayLoader_SetSecondarySelection(unsigned char value) { if (OverlayLoaderPushPrimarySelection_UnknownRoleZeroInitializedStorage[1]) OverlayLoaderSetSecondarySelection_UnknownRoleZeroInitializedStorage[OverlayLoaderPushPrimarySelection_UnknownRoleZeroInitializedStorage[1]-1]=value; }
