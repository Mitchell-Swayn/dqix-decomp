// Original ARM range reviewed.
// Original data: arm9/main @ 0x2107800; symbol: data_02107800.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char* ResourceTracks_GetResolvedResourceTable(char*);extern "C" unsigned int TextContextGetSharedInstance_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x02048C50; symbol: func_02048c50; size: 0x18.
extern "C" void GameObject_AllowBattleIdleMotion(char* p){char* q=*(char**)(p+0x13c);if(q)*(unsigned int*)(q+32)&=~256u;}
