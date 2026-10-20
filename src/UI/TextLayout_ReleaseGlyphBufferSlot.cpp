// Original ARM range reviewed.
// Original data: arm9/main @ 0x2107800; symbol: data_02107800.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char* ResourceTracks_GetResolvedResourceTable(char*);extern "C" unsigned int TextContextGetSharedInstance_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x02042AF4; symbol: func_02042af4; size: 0x1C.
extern "C" void TextLayout_ReleaseGlyphBufferSlot(int unused,unsigned char* p,int index){unsigned int bit=index&7;p[index>>3]&=~(1u<<bit);}
