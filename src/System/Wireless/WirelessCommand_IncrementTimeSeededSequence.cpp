#include <globaldefs.h>
ARM
#pragma opt_propagation off
// Original data: arm9/main @ 0x20f2304; symbol: data_020f2304.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000100.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned WirelessCommandIncrementTimeSeededSequence_UnknownRoleInitializedBytes;
extern "C" void RealTimeClock_InitializeIPCHandler();
extern "C" int RTC_GetTime(void*);
// Original: arm9/main @ 0x020D4DD4; symbol: func_020d4dd4; size: 0x74.
extern "C" unsigned short WirelessCommand_IncrementTimeSeededSequence() {
    unsigned words[3];
    if(WirelessCommandIncrementTimeSeededSequence_UnknownRoleInitializedBytes==65536) {
        RealTimeClock_InitializeIPCHandler();
        if(!RTC_GetTime(words)) WirelessCommandIncrementTimeSeededSequence_UnknownRoleInitializedBytes=(unsigned short)(words[2]+words[1]*256);
    }
    return WirelessCommandIncrementTimeSeededSequence_UnknownRoleInitializedBytes=(unsigned short)(WirelessCommandIncrementTimeSeededSequence_UnknownRoleInitializedBytes+1);
}
