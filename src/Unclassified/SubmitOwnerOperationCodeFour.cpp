#include <globaldefs.h>
#pragma optimization_level 4
extern "C" void DispatchCommandSixWithFourValues(void*, unsigned, void*, unsigned);
// Original: arm9/main @ 0x020D1E88; symbol: func_020d1e88; size: 0x18.
extern "C" ARM void SubmitOwnerOperationCodeFour(void* owner, void* data) { DispatchCommandSixWithFourValues(owner,4,data,1); }
