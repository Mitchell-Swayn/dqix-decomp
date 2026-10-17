#include <globaldefs.h>
ARM
extern "C" void DispatchInitializedObjectStateMemberCallback(void*);
// Original: arm9/ov023 @ 0x021FBD90; symbol: func_ov023_021fbd90; size: 0x1C.
extern "C" void func_ov023_021fbd90(void* p) { DispatchInitializedObjectStateMemberCallback((char*)p + 0x20); *(unsigned int*)((char*)p + 0x1c) = 2; }
