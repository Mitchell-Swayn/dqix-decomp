#include <globaldefs.h>
ARM
#pragma optimization_level 4
// Original data: arm9/main @ 0x20f2c5c; symbol: data_020f2c5c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 1210171b010000000200000000100000000000000000000000000000001000000000000000000000000000000010000000000000000000000000000000100000 ...; full span in module reference.
// Observed span: 72 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char GraphicsSubmitScaledBillboardMatrix_UnknownRoleInitializedBytes[];extern "C" void Graphics_BuildAndSubmitBillboardMatrix(int,void*,void*);
// Original: arm9/main @ 0x020E2FDC; symbol: func_020e2fdc; size: 0x1C.
extern "C" void Graphics_SubmitScaledBillboardMatrix(void* object){Graphics_BuildAndSubmitBillboardMatrix(1,object,GraphicsSubmitScaledBillboardMatrix_UnknownRoleInitializedBytes);}
