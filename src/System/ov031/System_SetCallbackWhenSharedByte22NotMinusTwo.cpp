#include <globaldefs.h>
ARM
extern "C" int ReadSharedSignedByteAtOffset22(void);
extern "C" void ClearGlobalControlByte18(void);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void func_ov031_02228aac(void);

// Original: arm9/ov031 @ 0x02228A84; symbol: func_ov031_02228a84; size: 0x28.
extern "C" void System_SetCallbackWhenSharedByte22NotMinusTwo(void) {
    if (ReadSharedSignedByteAtOffset22() == -2)
        return;
    ClearGlobalControlByte18();
    SetMainLoopCallback(func_ov031_02228aac);
}
