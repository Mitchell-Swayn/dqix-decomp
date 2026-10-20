#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void TextLayout_ComputeCenteredLineOrigins(void*,int*,int*);
// Original: arm9/main @ 0x02044830; symbol: func_02044830; size: 0xC.
extern "C" void TextWindow_ComputeCenteredLineOrigins(void* object,int* x,int* y){TextLayout_ComputeCenteredLineOrigins(object,x,y);}
