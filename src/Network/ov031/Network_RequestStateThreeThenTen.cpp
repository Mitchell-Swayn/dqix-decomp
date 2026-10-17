#include <globaldefs.h>
ARM
extern "C" void SetStateWithTransitionCallbacks(int);
extern "C" int WirelessCommand_InvokeFourArgumentRequestWithZeroMode(void*, unsigned, void*);
extern "C" void SetSharedObjectWord54UnlessStateNineOrTen(unsigned);
extern "C" void func_ov031_0223a0ac(void);
extern "C" void* data_ov031_02290d18;
// Original: arm9/ov031 @ 0x0223A060; symbol: func_ov031_0223a060; size: 0x4C.
extern "C" int Network_RequestStateThreeThenTen(void) {
    SetStateWithTransitionCallbacks(3);
    void* context = *(void**)((char*)&data_ov031_02290d18 + 4);
    int result = WirelessCommand_InvokeFourArgumentRequestWithZeroMode((char*)context + 0x80, (unsigned)&func_ov031_0223a0ac, (void*)2);
    if (result == 2) return 1;
    SetSharedObjectWord54UnlessStateNineOrTen((unsigned)result);
    SetStateWithTransitionCallbacks(10);
    return 0;
}
