// ARM instruction behavior reviewed; fields retain known byte offsets.
// Original data: arm9/main @ 0x210f840; symbol: data_0210f840.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Flags{unsigned int value:12;unsigned int rest:20;};extern "C" char ResourceManagerSetIndexedThirtySixByteRecordValue_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x02011AF0; symbol: func_02011af0; size: 0x34.
extern "C" void GameState_ClearTransitionFlagsPreservingBitFour(unsigned char* p){bool f=(p[0x63dc]&16)!=0;p[0x63dc]=0;if(f)p[0x63dc]|=16;}
