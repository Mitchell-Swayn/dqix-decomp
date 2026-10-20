#include <globaldefs.h>
extern "C" void* memset(void*,int,unsigned);
// Original data: arm9/ov012 @ 0x218afbc; symbol: data_ov012_0218afbc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 3a000000005b000000005d000000007b000000007d000000005e000000002d000000002e0000000024000000002f00000000400000000026000000002c000000 ...; full span in module reference.
// Observed span: 76 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov012.md.
extern "C" unsigned char ProfileTextFilterInitializeGlyphLookup_UnknownRoleInitializedBytes[];
extern "C" int TextLookup_FindGlyphIndexByText(void*,int);
// Original: arm9/ov012 @ 0x021845F8; symbol: func_ov012_021845f8; size: 0x5C.
extern "C" ARM void ProfileTextFilter_InitializeGlyphLookup(unsigned char* self) { memset(self+0x18,0,12); *(unsigned*)(self+0x24)=0; *(unsigned short*)(self+0x28)=0; unsigned char* output=self+0x2a; for(int i=0;i<15;++i) *output++=TextLookup_FindGlyphIndexByText(ProfileTextFilterInitializeGlyphLookup_UnknownRoleInitializedBytes+i*5,1); }
