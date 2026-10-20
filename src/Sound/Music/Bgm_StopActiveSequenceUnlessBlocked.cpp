#include <globaldefs.h>
#pragma optimization_level 4
#pragma optimize_for_size off
extern "C" void ResourceHandle_UpdateAndInvokeObjectCommand(int, int, unsigned int, unsigned int);
// Original: arm9/main @ 0x0209C678; symbol: func_0209c678; size: 0x44.
extern "C" void Bgm_StopActiveSequenceUnlessBlocked(int param_1, unsigned int param_2, unsigned int unused3, unsigned int unused4) {
    unsigned int flags = *(unsigned char *)(param_1 + 0xc8);
    if (((flags << 29) >> 31) != 0) return;
    int state = *(int *)(param_1 + 0xb0);
    if (state == 1) {
        ResourceHandle_UpdateAndInvokeObjectCommand(param_1, param_1 + 0xbc, param_2, flags);
        return;
    }
    if (state != 2) return;
    ResourceHandle_UpdateAndInvokeObjectCommand(param_1, param_1 + 0xc0, param_2, flags);
}
