#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x20e7380; symbol: data_020e7380.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0f0e0d0c0b0a09080706050403020100.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20fe9a4; symbol: data_020fe9a4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Canvas{unsigned char bytes[0xe0];};struct Globals{void* resource;unsigned color;};extern "C" {extern Globals DebugMenuUpdateAndRender_UnknownRoleZeroInitializedStorage;extern unsigned char TextSubmitStringAtScreenPosition_UnknownRoleInitializedBytes[];void TextCanvas_InitializeLayoutAndTransferDefaults(unsigned char*);void TextCanvas_RenderStyledTextAndMeasure(void*,short,short,char*,unsigned char,unsigned char,short*,short*,int);}
// Original: arm9/main @ 0x02029140; symbol: Text_SubmitStringAtScreenPosition; size: 0xcc.
extern "C" void Text_SubmitStringAtScreenPosition(int x,int y,char* text){if(!DebugMenuUpdateAndRender_UnknownRoleZeroInitializedStorage.resource)return;if(x>=256||y>=192)return;if(!text)return;Canvas canvas;short height,width;TextCanvas_InitializeLayoutAndTransferDefaults(canvas.bytes);canvas.bytes[0xc5]&=~4;*(unsigned short*)(canvas.bytes+0xa8)=32;*(unsigned short*)(canvas.bytes+0xaa)=24;*(void**)(canvas.bytes+8)=DebugMenuUpdateAndRender_UnknownRoleZeroInitializedStorage.resource;canvas.bytes[0xc5]&=~16;TextCanvas_RenderStyledTextAndMeasure(&canvas,(short)x,(short)y,text,8,TextSubmitStringAtScreenPosition_UnknownRoleInitializedBytes[DebugMenuUpdateAndRender_UnknownRoleZeroInitializedStorage.color],&height,&width,1);}
