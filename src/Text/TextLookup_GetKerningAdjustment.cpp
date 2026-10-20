#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x210782c; symbol: data_0210782c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char* TextLookupFindGlyphIndexByText_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020425E4; symbol: func_020425e4; size: 0x54.
extern "C" int TextLookup_GetKerningAdjustment(unsigned int a,unsigned int b,int table) { unsigned char* p=TextLookupFindGlyphIndexByText_UnknownRoleZeroInitializedStorage[table];unsigned short key=(a&255)|((b&255)<<8);unsigned int count=*(unsigned int*)(p+8);unsigned char* entry=*(unsigned char**)(p+12);for(unsigned int i=0;i<count;entry+=4,i++)if(*(unsigned short*)entry==key)return *(signed char*)(entry+2);return 0; }
