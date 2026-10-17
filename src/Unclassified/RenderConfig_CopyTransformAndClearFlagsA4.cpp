#include <globaldefs.h>
extern "C" unsigned data_0210a010[]; extern "C" void MI_Copy36B(void*,void*);
// Original: arm9/main @ 0x02016D8C; symbol: func_02016d8c; size: 0x28.
extern "C" void RenderConfig_CopyTransformAndClearFlagsA4(void* input) { MI_Copy36B(input,&data_0210a010[47]); data_0210a010[63] &= ~0xa4u; }
