#include <globaldefs.h>
extern "C" unsigned char data_ov031_02290cb4[];
extern "C" void Graphics_LoadScreenData0224BBF8AndSetBackgroundPriorities();
extern "C" void System_ConvertSharedRegionByteToIndexPlusFive();
extern "C" void Graphics_SubmitIndexedConfiguredBuffer(unsigned);
extern "C" void System_ResolveGlobalGroupEntry(unsigned);
extern "C" void Graphics_InitializeSecondaryMainDisplayCallback();
extern "C" void SetMainLoopCallback(void (*)());
// Original: arm9/ov031 @ 0x02231988; symbol: func_ov031_02231988; size: 0x3C.
extern "C" ARM void Ov031_InitializeTransitionSequence() {
    data_ov031_02290cb4[0] = 0;
    Graphics_LoadScreenData0224BBF8AndSetBackgroundPriorities();
    System_ConvertSharedRegionByteToIndexPlusFive();
    Graphics_SubmitIndexedConfiguredBuffer(0x26);
    System_ResolveGlobalGroupEntry(0x10);
    SetMainLoopCallback(Graphics_InitializeSecondaryMainDisplayCallback);
}
