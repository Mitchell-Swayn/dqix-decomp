extern "C"
{
// Original data: arm9/ov000 @ 0x2184220; symbol: data_ov000_02184220.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
    extern unsigned BattleSceneUpdate_UnknownRoleZeroInitializedStorage[];
}
// Layout projections describe observed offsets; higher-level ownership is unresolved.
// Original: arm9/ov000 @ 0x02160130; symbol: func_ov000_02160130; size: 0x10.
extern "C" unsigned BattleScene_GetActiveInstance()
{
    return BattleSceneUpdate_UnknownRoleZeroInitializedStorage[1];
}
