#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x20e7b98; symbol: data_020e7b98.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0008000000100000001000000020000000020000000800000020000000800000.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned int GraphicsClearScreenBuffer_UnknownRoleInitializedBytes[][4];extern "C" void* memset(void*,int,unsigned int);
// Original: arm9/main @ 0x0204B010; symbol: func_0204b010; size: 0x3C.
extern "C" void Graphics_ClearScreenBuffer(unsigned char* p,void* buffer) { if(!buffer)buffer=*(void**)(p+0x14);if(!buffer)return;memset(buffer,0,GraphicsClearScreenBuffer_UnknownRoleInitializedBytes[p[0x1f]][*(unsigned int*)(p+0x18)]); }
