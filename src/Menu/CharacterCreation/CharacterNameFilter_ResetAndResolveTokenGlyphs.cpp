#include <globaldefs.h>
ARM
extern "C" void* memset(void*,int,unsigned);
extern "C" int TextLookup_FindGlyphIndexByText(const char*,int);
// Original data: arm9/ov009 @ 0x218aafc; symbol: data_ov009_0218aafc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 3a000000005b000000005d000000007b000000007d000000005e000000002d000000002e0000000024000000002f00000000400000000026000000002c000000 ...; full span in module reference.
// Observed span: 76 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov009.md.
extern "C" const char CharacterNameFilterResetAndResolveTokenGlyphs_UnknownRoleInitializedBytes[15][5];
struct CharacterFilter { char unknown[0x18]; int cleared[3]; int count; short flags; unsigned char enabled[15]; };
// Original: arm9/ov009 @ 0x021847EC; symbol: func_ov009_021847ec; size: 0x5C.
extern "C" void CharacterNameFilter_ResetAndResolveTokenGlyphs(CharacterFilter* state) {
 memset(state->cleared,0,12);state->count=0;state->flags=0;
 unsigned char* enabled=state->enabled;for(int i=0;i<15;i++) *enabled++=TextLookup_FindGlyphIndexByText(CharacterNameFilterResetAndResolveTokenGlyphs_UnknownRoleInitializedBytes[i],1);
}
