#include <globaldefs.h>
#pragma optimization_level 4
#pragma optimize_for_size off
extern "C" int Window_AllocateStagingBufferAndInitializeTextEntries(int);
extern "C" void func_02066cf0(int, int);
extern "C" void Graphics_StagePresentResourceRegion(int);
extern "C" void Graphics_FreePointedVRAMStagingMemory(int);
// Original: arm9/main @ 0x020444E0; symbol: func_020444e0; size: 0x50.
extern "C" void ClearOwnerFieldAndFreeReadyLinkedVRAMBuffer(int param_1) {
    int value = *(int *)(param_1 + 0x38);
    if (value != 0) {
        if (Window_AllocateStagingBufferAndInitializeTextEntries(value) == 0) return;
        func_02066cf0(param_1, 0);
        Graphics_StagePresentResourceRegion(*(int *)(param_1 + 0x38));
        Graphics_FreePointedVRAMStagingMemory(*(int *)(param_1 + 0x38));
        return;
    }
    func_02066cf0(param_1, 0);
}
