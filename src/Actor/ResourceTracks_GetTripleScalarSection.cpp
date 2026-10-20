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
// Original: arm9/main @ 0x020550A8; symbol: func_020550a8; size: 0x18.
extern "C" int ResourceTracks_GetTripleScalarSection(char* p){char* q=ResourceTracks_GetResolvedResourceTable(p);int v;if(q==0)v=0;else v=*(int*)(q+4);return v;}
