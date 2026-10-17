#include <globaldefs.h>
struct ResourceTag{signed char index;unsigned char flags,first,second;};extern "C" void InitializeFourWordsWithInvalidIndex(ResourceTag*);
#pragma dont_inline on
// Original: arm9/ov030 @ 0x021D928C; symbol: func_ov030_021d928c; size: 0x14.
extern "C" ARM ResourceTag* func_ov030_021d928c(ResourceTag* p){InitializeFourWordsWithInvalidIndex(p);return p;}
