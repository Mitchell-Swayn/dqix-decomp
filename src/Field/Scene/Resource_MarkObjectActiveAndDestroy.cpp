#include <globaldefs.h>
ARM
extern "C" void Resource_DestroyAndFreeAllocatedObject(void *);
// Original: arm9/ov017 @ 0x021C30F8; symbol: func_ov017_021c30f8; size: 0x14.
extern "C" void Resource_MarkObjectActiveAndDestroy(void *p) { *((unsigned char *)p + 1) = 1; Resource_DestroyAndFreeAllocatedObject(p); }
