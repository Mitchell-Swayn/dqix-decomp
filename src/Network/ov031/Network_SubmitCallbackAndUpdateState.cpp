#include <globaldefs.h>
ARM
extern "C" int WirelessCommand_SubmitOpcodeOne(void *p);
extern "C" void SetStateWithTransitionCallbacks(int value);
extern "C" void SetSharedObjectWord54UnlessStateNineOrTen(unsigned value);
extern "C" void func_ov031_02239b64(void);
// Original: arm9/ov031 @ 0x02239B34; symbol: func_ov031_02239b34; size: 0x30.
extern "C" int Network_SubmitCallbackAndUpdateState(void) {
    SetStateWithTransitionCallbacks(3);
    int result = WirelessCommand_SubmitOpcodeOne((void *)func_ov031_02239b64);
    if (result == 2)
        return 1;
    SetSharedObjectWord54UnlessStateNineOrTen(result);
    return 0;
}
