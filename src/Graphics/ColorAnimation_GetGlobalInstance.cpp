// Reviewed original instruction stream; opaque fields require later semantic naming.
// Original data: arm9/main @ 0x2108d5c; symbol: data_02108d5c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char ColorAnimationGetGlobalInstance_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020704FC; symbol: func_020704fc; size: 0xC.
extern "C" void* ColorAnimation_GetGlobalInstance(){return ColorAnimationGetGlobalInstance_UnknownRoleZeroInitializedStorage;}
