#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_02290cdc[];
extern "C" void Graphics_LoadMainBG2ResourceBdb4AndSetPriorities();
extern "C" void System_CreateCopyAndFinalizeResource(unsigned);
extern "C" void Graphics_SubmitIndexedConfiguredBuffer(unsigned);
extern "C" void System_ResolveGlobalGroupEntry(unsigned);
extern "C" void SetMainLoopCallback(void (*)());
extern "C" void System_ConfigureDisplayAndRegisterMainLoopB();
// Original: arm9/ov031 @ 0x02234314; symbol: func_ov031_02234314; size: 0x40.
extern "C" void System_ResetAndStartResourceSequence(void) {
    data_ov031_02290cdc[0] = 0;
    Graphics_LoadMainBG2ResourceBdb4AndSetPriorities();
    System_CreateCopyAndFinalizeResource(8);
    Graphics_SubmitIndexedConfiguredBuffer(0x29);
    System_ResolveGlobalGroupEntry(0x10);
    SetMainLoopCallback(System_ConfigureDisplayAndRegisterMainLoopB);
}
