#include <globaldefs.h>
ARM
extern "C" int WirelessSetup_CopyReceivedConfiguration(void *destination);
extern "C" void DisableInterruptsAndHaltForever(void);
extern "C" void WfcUtility_ImportSsidAndWepKeysIntoSelectedProfile(void *source);
// Original: arm9/ov031 @ 0x02227C84; symbol: System_ConfigureSharedStateFromValidatedBuffer; size: 0x2C.
// Builds a 0xe8-byte temporary record, halts if its builder does not return 1, then applies the record to shared state.
extern "C" void System_ConfigureSharedStateFromValidatedBuffer(void) {
    unsigned char buffer[0xe8];
    if (WirelessSetup_CopyReceivedConfiguration(buffer) != 1)
        DisableInterruptsAndHaltForever();
    WfcUtility_ImportSsidAndWepKeysIntoSelectedProfile(buffer);
}
