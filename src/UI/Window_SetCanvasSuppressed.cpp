// Original ARM range reviewed.
// Original data: arm9/main @ 0x2107800; symbol: data_02107800.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char* ResourceTracks_GetResolvedResourceTable(char*);extern "C" unsigned int TextContextGetSharedInstance_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x0205D5B8; symbol: func_0205d5b8; size: 0x18.
extern "C" void Window_SetCanvasSuppressed(unsigned char* p,int v){unsigned int byte=p[0xc5];if(v)byte|=32;else byte&=~32u;p[0xc5]=byte;}
