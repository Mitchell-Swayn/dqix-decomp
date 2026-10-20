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
// Original: arm9/main @ 0x02045824; symbol: func_02045824; size: 0x40.
extern "C" void TextWindow_SetControlDelays(char* p,int value,int i){if(i==-1){for(int n=0;n<4;++n)*(int*)(p+n*4+0x186c)=value;}else *(int*)(p+i*4+0x186c)=value;}
