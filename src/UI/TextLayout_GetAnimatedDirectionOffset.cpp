#include <globaldefs.h>
#pragma optimize_for_size off
// Original data: arm9/main @ 0x20e7e10; symbol: data_020e7e10.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex fe00000000001f0074000000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20e7e1c; symbol: data_020e7e1c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000fd0006000000003000000e00ffffc0000000.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" volatile signed char TextLayoutGetAnimatedDirectionOffset_UnknownRoleInitializedBytes[],TextLayoutGetAnimatedDirectionOffset_UnknownRoleInitializedBytes_Variant2[];
// Original: arm9/main @ 0x0206B804; symbol: func_0206b804; size: 0x58.
extern "C" ARM void TextLayout_GetAnimatedDirectionOffset(unsigned char* self,int* x,int* y) { *y=0; *x=0; if(!self[0x19c0])return; self[0x19cd]=1; *(int*)(self+64)=0; unsigned int direction=self[0x195d]&3; signed char dx=TextLayoutGetAnimatedDirectionOffset_UnknownRoleInitializedBytes[direction]; signed char dy=TextLayoutGetAnimatedDirectionOffset_UnknownRoleInitializedBytes_Variant2[direction]; *x=dx;*y=dy; }
