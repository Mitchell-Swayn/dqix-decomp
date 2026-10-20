#include <globaldefs.h>
ARM
extern "C" void FieldCommandQueue_DrawActiveCommandWorldObjects(void *, void *);
// Original: arm9/ov017 @ 0x021A3DCC; symbol: func_ov017_021a3dcc; size: 0x10.
extern "C" void FieldCommandQueue_DrawFrontWorldObjects(void *p) { FieldCommandQueue_DrawActiveCommandWorldObjects(p, *(void **)p); }
