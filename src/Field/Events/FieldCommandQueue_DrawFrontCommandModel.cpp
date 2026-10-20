#include <globaldefs.h>
ARM
extern "C" void FieldCommandQueue_DrawCommandModelForActiveCommand(void*, unsigned int);
// Original: arm9/ov017 @ 0x021A3AF0; symbol: func_ov017_021a3af0; size: 0x10.
extern "C" void FieldCommandQueue_DrawFrontCommandModel(void* p) { FieldCommandQueue_DrawCommandModelForActiveCommand(p, *(unsigned int*)p); }
