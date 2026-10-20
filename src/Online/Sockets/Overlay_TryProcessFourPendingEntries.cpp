#include <globaldefs.h>
ARM
extern "C" void Network_InitializeCurrentThreadSocket();
extern "C" void Network_EnableUdpSocketMode();
extern "C" void Resource_UpdateSelectedRecordModesFromEnableState(int, int, int);
extern "C" int Network_SendDhcpDiscover();
extern "C" int Network_WaitForDhcpReplyAndApplyOptions(int, int);
extern "C" void Network_DeactivateCurrentThreadSocket();
// Original: arm9/ov031 @ 0x022046B8; symbol: func_ov031_022046b8; size: 0x58.
extern "C" int Overlay_TryProcessFourPendingEntries() {
    Network_InitializeCurrentThreadSocket();
    Network_EnableUdpSocketMode();
    Resource_UpdateSelectedRecordModesFromEnableState(0x44, 0x43, -1);
    int result;
    int index = 0;
    do {
        int value = Network_SendDhcpDiscover();
        result = Network_WaitForDhcpReplyAndApplyOptions(value, index);
        if (result == 1) break;
        ++index;
    } while (index < 4);
    Network_DeactivateCurrentThreadSocket();
    return result == 1;
}
