#include <globaldefs.h>
ARM
extern "C" void Network_GetConnectionWorkspace(unsigned mask);
extern "C" int WfcNetCheck_AllocateSessionAndStartWorker(void);
extern "C" void GameState_SetSelectedStateWordFields(int value);
// Original: arm9/ov031 @ 0x0221544C; symbol: func_ov031_0221544c; size: 0x2C.
extern "C" int System_SelectStateWithFallback(void) {
    Network_GetConnectionWorkspace(8);
    if (WfcNetCheck_AllocateSessionAndStartWorker() == 0) return 0x0e;
    GameState_SetSelectedStateWordFields(3);
    return 0x11;
}
