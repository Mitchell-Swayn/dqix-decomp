// Reviewed original ARM instructions; field semantics unresolved.
// Original data: arm9/main @ 0x20fe9a4; symbol: data_020fe9a4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x210f844; symbol: data_0210f844.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1120 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2111824; symbol: data_02111824.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 60 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char* ResourceTracks_GetResolvedResourceTable(char*);extern "C" char SoundSetPlayerVolume_UnknownRoleZeroInitializedStorage[];extern "C" volatile unsigned int RealTimeClockWaitForRequestCompletion_UnknownRoleZeroInitializedStorage[];extern "C" unsigned int DebugMenuUpdateAndRender_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x02028DDC; symbol: func_02028ddc; size: 0x10.
extern "C" void DebugText_SetRenderBuffer(unsigned int v){DebugMenuUpdateAndRender_UnknownRoleZeroInitializedStorage[0]=v;}
