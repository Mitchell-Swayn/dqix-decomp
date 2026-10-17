#include <globaldefs.h>
ARM
extern "C" void func_ov014_02186d7c(void*);
// Original: arm9/ov017 @ 0x021C0538; symbol: func_ov017_021c0538; size: 0x18.
extern "C" void func_ov017_021c0538(void* p) { void* owner = *(void**)((char*)p + 0x20); if (owner) func_ov014_02186d7c(owner); }
