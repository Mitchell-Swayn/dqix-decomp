// ARM range reviewed; all named globals checked against exact relocations.
// Original data: arm9/main @ 0x20e8ebc; symbol: data_020e8ebc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0e101113141516ff.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2101640; symbol: data_02101640.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 64 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2107850; symbol: data_02107850.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Mode{int low:18;int value:3;int high:11;};extern "C" signed char BgmShouldReplacePrimarySequence_UnknownRoleInitializedBytes[];extern "C" char CombatantMotionAdvanceSidestep_UnknownRoleZeroInitializedStorage[];extern "C" unsigned int NetworkBeginModeValidationRequest_UnknownRoleZeroInitializedStorage_Variant2[];
// Original: arm9/main @ 0x02087D24; symbol: func_02087d24; size: 0x54.
extern "C" int CombatStatus_CanAdjustSpellResistanceStage(char* p,int dir){if(*(unsigned int*)(p+20)&1)return 0;if(dir==0){int v=((Mode*)(p+0x58))->value;if(v<2)return 1;}else{int v=((Mode*)(p+0x58))->value;if(v>-2)return 1;}return 0;}
