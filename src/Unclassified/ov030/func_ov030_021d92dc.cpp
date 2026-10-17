#include <globaldefs.h>
struct ResourceTag{signed char index;unsigned char flags,first,second;};extern "C" void InitializeFourWordsWithInvalidIndex(ResourceTag*);
#pragma dont_inline on
// Original: arm9/ov030 @ 0x021D92DC; symbol: func_ov030_021d92dc; size: 0x14.
extern "C" ARM ResourceTag* func_ov030_021d92dc(ResourceTag* p){InitializeFourWordsWithInvalidIndex(p);return p;}
