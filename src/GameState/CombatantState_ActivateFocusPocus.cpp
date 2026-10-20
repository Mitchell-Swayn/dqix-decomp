// Original instruction control flow and relocations reviewed.
// Original data: arm9/main @ 0x2108d70; symbol: data_02108d70.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x210f3c0; symbol: data_0210f3c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2110370; symbol: data_02110370.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char* NNSSndArcGetCurrent_UnknownRoleZeroInitializedStorage[];extern "C" unsigned short ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage[];extern "C" unsigned int SoundReleaseStreamAlarmSlot_UnknownRoleZeroInitializedStorage[];struct Flag{unsigned char enabled:1;unsigned char rest:7;};
// Original: arm9/main @ 0x02088B64; symbol: func_02088b64; size: 0x20.
extern "C" void CombatantState_ActivateFocusPocus(char* p){p[0x68]=6;p[0x8b]=0;*(unsigned int*)(p+20)|=0x40000000;}
