#include <globaldefs.h>
ARM
extern "C" unsigned Network_GetConnectionPhase();
extern "C" void Network_ReleaseConnectionWorkspaces();
extern "C" void Network_UpdateConnectionProgress(unsigned char);
extern "C" int Network_AdvanceConnectionShutdown(unsigned char*);
// Original: arm9/ov031 @ 0x022130AC; symbol: func_ov031_022130ac; size: 0x3C.
// Zero and terminal state0x12 dispatch priority handlers; other states advance before recording the selected byte.
extern "C" int System_AdvanceSharedSequenceOrDispatchPriorityState() {
    unsigned char state = Network_GetConnectionPhase();
    if (state == 0 || state == 0x12) {
        Network_ReleaseConnectionWorkspaces();
        return 1;
    }
    Network_AdvanceConnectionShutdown(&state);
    Network_UpdateConnectionProgress(state);
    return 0;
}
