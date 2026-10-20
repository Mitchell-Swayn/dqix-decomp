#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x210782c; symbol: data_0210782c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char* TextLookupFindGlyphIndexByText_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020425B4; symbol: func_020425b4; size: 0x30.
extern "C" unsigned char* TextLookup_GetGlyphEntryByIndex(unsigned int i,int table) { unsigned char* p=TextLookupFindGlyphIndexByText_UnknownRoleZeroInitializedStorage[table];if ((int)i>=0 && i<*(unsigned int*)(p+4))return *(unsigned char**)(p+0x10)+i*8;return 0; }
