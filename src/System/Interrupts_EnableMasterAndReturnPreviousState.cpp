// Original ARM range reviewed.
// Original data: arm9/main @ 0x2107800; symbol: data_02107800.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char* ResourceTracks_GetResolvedResourceTable(char*);extern "C" unsigned int TextContextGetSharedInstance_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020D6C9C; symbol: func_020d6c9c; size: 0x18.
extern "C" unsigned int Interrupts_EnableMasterAndReturnPreviousState(){volatile unsigned short* reg=(volatile unsigned short*)0x04000208;unsigned int old=*reg;*reg=1;return old;}
