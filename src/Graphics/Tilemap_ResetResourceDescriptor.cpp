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
// Original: arm9/main @ 0x0204ACB0; symbol: func_0204acb0; size: 0x20.
extern "C" void Tilemap_ResetResourceDescriptor(char* p){*(short*)p=0;*(short*)(p+2)=0;p[4]=0;p[5]=0;*(int*)(p+8)=0;*(int*)(p+12)=0;}
