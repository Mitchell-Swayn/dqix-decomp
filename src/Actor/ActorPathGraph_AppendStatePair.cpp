#include <globaldefs.h>
#pragma optimization_level 4
#pragma optimize_for_size off
// Original: arm9/main @ 0x02028378; symbol: func_02028378; size: 0x48.
extern "C" void ActorPathGraph_AppendStatePair(int param_1, unsigned short *param_2) {
    unsigned int base = *(unsigned int *)(param_1 + 0x28);
    if (base == 0) return;
    register unsigned int index = *(unsigned char *)(param_1 + 0x25);
    if (*(unsigned char *)(param_1 + 0x24) <= index) return;
    *(unsigned short *)(base + index * 4) = param_2[0];
    *(unsigned short *)(base + index * 4 + 2) = param_2[1];
    *(unsigned char *)(param_1 + 0x25) = *(unsigned char *)(param_1 + 0x25) + 1;
}
