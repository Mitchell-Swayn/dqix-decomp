#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
// Original data: arm9/main @ 0x20f0079; symbol: data_020f0079.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 733700.
// Observed span: 3 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20f007c; symbol: data_020f007c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 6d6500.
// Observed span: 3 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x210782c; symbol: data_0210782c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2107830; symbol: data_02107830.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2107834; symbol: data_02107834.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2107838; symbol: data_02107838.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char LoadTwoFontArchivesUnderLoaderLock_UnknownRoleInitializedBytes[],LoadTwoFontArchivesUnderLoaderLock_UnknownRoleInitializedBytes_Variant2[],TextLookupFindGlyphIndexByText_UnknownRoleZeroInitializedStorage[],LoadTwoFontArchivesUnderLoaderLock_UnknownRoleZeroInitializedStorage[],TextDrawClippedGlyphMask4Bpp_UnknownRoleZeroInitializedStorage[],LoadTwoFontArchivesUnderLoaderLock_UnknownRoleZeroInitializedStorage_Variant2[];extern "C" void TextLookup_LoadAndRelocateTwoResourceFiles(void*,void*,void*,void*);
// Original: arm9/main @ 0x02042944; symbol: func_02042944; size: 0x54.
extern "C" ARM void LoadTwoFontArchivesUnderLoaderLock(void* p){BackgroundLoader::AddLockGlobal();TextLookup_LoadAndRelocateTwoResourceFiles(p,LoadTwoFontArchivesUnderLoaderLock_UnknownRoleInitializedBytes,TextLookupFindGlyphIndexByText_UnknownRoleZeroInitializedStorage,TextDrawClippedGlyphMask4Bpp_UnknownRoleZeroInitializedStorage);TextLookup_LoadAndRelocateTwoResourceFiles(p,LoadTwoFontArchivesUnderLoaderLock_UnknownRoleInitializedBytes_Variant2,LoadTwoFontArchivesUnderLoaderLock_UnknownRoleZeroInitializedStorage,LoadTwoFontArchivesUnderLoaderLock_UnknownRoleZeroInitializedStorage_Variant2);BackgroundLoader::RemoveLockGlobal();}
