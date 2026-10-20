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
// Original: arm9/main @ 0x02046968; symbol: func_02046968; size: 0x4C.
extern "C" void LinkedQueue_RemoveCompletedFrontNodesOrMarkWaiting(unsigned char** p){while(*p){unsigned char* node=*p;if(node[1]){node[2]=0;(*p)[3]=0;*p=*(unsigned char**)(*p+4);}else{node[3]=1;return;}}}
