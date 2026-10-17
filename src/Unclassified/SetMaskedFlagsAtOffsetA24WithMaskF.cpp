#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020D76FC; symbol: func_020d76fc; size: 0x20.
extern "C" void SetMaskedFlagsAtOffsetA24WithMaskF(unsigned char* p) { unsigned short value=*(unsigned short*)(p+0xa24)&15; *(unsigned short*)(p+0xa26)|=value; }
