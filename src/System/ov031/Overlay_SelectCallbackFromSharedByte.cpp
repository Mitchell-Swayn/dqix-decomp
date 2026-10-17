#include <globaldefs.h>
ARM
extern "C" int ReadSharedSignedByteAtOffset22();
extern "C" void System_ResolveGlobalGroupEntry(unsigned);
extern "C" void SetMainLoopCallback(void (*)(void));
extern "C" void func_ov031_02234770(void);
extern "C" volatile unsigned char data_ov031_02290ce0[];
// Original: arm9/ov031 @ 0x02234720; symbol: func_ov031_02234720; size: 0x50.
extern "C" void Overlay_SelectCallbackFromSharedByte(void) {
    int value = ReadSharedSignedByteAtOffset22();
    if (value == 0) goto case_zero;
    if (value == 1) goto case_one;
    return;
case_zero:
    System_ResolveGlobalGroupEntry(7);
    goto set_callback;
case_one:
    System_ResolveGlobalGroupEntry(6);
    data_ov031_02290ce0[0] = 1;
set_callback:
    SetMainLoopCallback(func_ov031_02234770);
}
