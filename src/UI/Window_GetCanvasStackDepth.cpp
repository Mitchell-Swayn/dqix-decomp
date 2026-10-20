// Instruction behavior and offsets reviewed; names/parent layout remain unresolved.
// Original data: arm9/main @ 0x2109d8c; symbol: data_02109d8c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2109da4; symbol: data_02109da4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x21118e0; symbol: data_021118e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1568 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned int ScriptListContextGetActiveInstance_UnknownRoleZeroInitializedStorage[];extern "C" char OverlayLoaderPushPrimarySelection_UnknownRoleZeroInitializedStorage[];extern "C" unsigned int* TryReadViaDMA_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x0205D67C; symbol: func_0205d67c; size: 0x24.
extern "C" unsigned int Window_GetCanvasStackDepth(char* p){if(!*(int*)(p+0x98))return 0;return *(int*)(p+0x9c)?(unsigned char)p[0xb4]:0;}
