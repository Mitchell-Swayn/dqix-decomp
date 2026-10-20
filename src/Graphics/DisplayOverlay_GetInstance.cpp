// ARM instruction evidence reviewed; opaque field offsets preserve observed layout.
// Original data: arm9/main @ 0x214e4c8; symbol: data_0214e4c8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 232 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char DisplayOverlayGetInstance_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020DAF90; symbol: func_020daf90; size: 0xC.
 extern "C" void* DisplayOverlay_GetInstance() {return DisplayOverlayGetInstance_UnknownRoleZeroInitializedStorage;}
