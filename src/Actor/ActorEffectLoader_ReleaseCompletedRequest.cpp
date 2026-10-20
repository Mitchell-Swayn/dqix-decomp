// ARM instruction behavior reviewed; fields retain known byte offsets.
// Original data: arm9/main @ 0x210f840; symbol: data_0210f840.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Flags{unsigned int value:12;unsigned int rest:20;};extern "C" char ResourceManagerSetIndexedThirtySixByteRecordValue_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020DA2E4; symbol: func_020da2e4; size: 0x18.
extern "C" void ActorEffectLoader_ReleaseCompletedRequest(char* p){*(int*)(p+8)=-1;*(int*)p=-1;p[4]=0;}
