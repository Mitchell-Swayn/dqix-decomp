// Original data: arm9/main @ 0x2107800; symbol: data_02107800.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned int TextContextGetSharedInstance_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020429BC; symbol: func_020429bc; size: 0x18.
extern "C" unsigned int TextLookup_ReadGlobalResourceForTypeEight(int type){unsigned int ret=0;if(type==8)ret=TextContextGetSharedInstance_UnknownRoleZeroInitializedStorage[4];return ret;}
