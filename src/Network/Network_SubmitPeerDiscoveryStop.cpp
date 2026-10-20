#include <globaldefs.h>
extern "C" int WM_EndScan(void *);
extern "C" void Network_RecordWirelessErrorUnlessTerminal(int);
extern "C" void Network_HandleRestartCompletionAndPendingMode(void);

// Original: arm9/main @ 0x0202D0E0; symbol: func_0202d0e0; size: 0x28.
extern "C" int Network_SubmitPeerDiscoveryStop(void) {
    int result = WM_EndScan((void *)Network_HandleRestartCompletionAndPendingMode);
    if (result != 2) {
        Network_RecordWirelessErrorUnlessTerminal(result);
        return 0;
    }
    return 1;
}
