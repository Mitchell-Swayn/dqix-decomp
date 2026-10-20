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
// Original: arm9/main @ 0x02053DA0; symbol: func_02053da0; size: 0x20.
extern "C" void GameObject_BindAndResetCombatTrackingRecord(char* p,char* q){*(char**)(p+0x19c)=q;*(short*)q=0;q[2]=0;q[3]=0;q[4]=0;*(int*)(q+8)=0;}
