// ARM instruction evidence reviewed; opaque field offsets preserve observed layout.
// Original data: arm9/main @ 0x2109da4; symbol: data_02109da4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char OverlayLoaderPushPrimarySelection_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020A1EDC; symbol: func_020a1edc; size: 0x14.
extern "C" void OverlayLoader_ResetSecondarySelectionStack(){OverlayLoaderPushPrimarySelection_UnknownRoleZeroInitializedStorage[1]=0;}
