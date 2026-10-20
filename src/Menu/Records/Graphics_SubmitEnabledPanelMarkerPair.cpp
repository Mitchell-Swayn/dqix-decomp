#include <globaldefs.h>
ARM
// Original data: arm9/ov008 @ 0x218b300; symbol: data_ov008_0218b300.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0f1000000060040000020000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov008.md.
// Original data: arm9/ov008 @ 0x218b30c; symbol: data_ov008_0218b30c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0001010101000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov008.md.
// Original data: arm9/ov008 @ 0x218b314; symbol: data_ov008_0218b314.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0010000000800600.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov008.md.
extern "C" const signed char GraphicsSubmitEnabledPanelMarkerPair_UnknownRoleInitializedBytes[];extern "C" const unsigned GraphicsSubmitEnabledPanelMarkerPair_UnknownRoleInitializedBytes_Variant3[];extern "C" const unsigned char GraphicsSubmitEnabledPanelMarkerPair_UnknownRoleInitializedBytes_Variant2[];extern "C" void Graphics_SetCellPriority(void*,void*,int);extern "C" void Graphics_SubmitTransformedCellToOam(void*,void*);
// Original: arm9/ov008 @ 0x02188934; symbol: func_ov008_02188934; size: 0xC4.
// Selects a two-byte marker mask and submits enabled forty-byte marker records at fixed coordinates.
extern "C" void Graphics_SubmitEnabledPanelMarkerPair(unsigned char* self){if(!*(void**)(self+0x730))return;unsigned flags=*(unsigned*)(self+0xb18);if(!(flags&16))return;if(!(flags&0x80000))return;for(int i=0;i<2;i++){unsigned mode=self[0x74c];unsigned index=self[0xb29];if(mode==7 && index==1)index=2;if(!(GraphicsSubmitEnabledPanelMarkerPair_UnknownRoleInitializedBytes_Variant2+index*2)[i])continue;unsigned y=GraphicsSubmitEnabledPanelMarkerPair_UnknownRoleInitializedBytes_Variant3[i];int which=GraphicsSubmitEnabledPanelMarkerPair_UnknownRoleInitializedBytes[i];char* base=*(char**)(self+0x734);int offset=which*40;struct Marker{char prefix[20];unsigned x,y;char suffix[12];};Marker* entry=(Marker*)(base+offset);entry->x=0x46000;entry->y=y;Graphics_SetCellPriority(*(void**)(self+0x730),*(char**)(self+0x734)+offset,1);Graphics_SubmitTransformedCellToOam(*(void**)(self+0x730),*(char**)(self+0x734)+offset);}}
