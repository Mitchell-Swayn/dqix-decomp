#include <globaldefs.h>
ARM
extern "C" void* Network_GetConnectionWorkspace(unsigned);
// Original: arm9/ov031 @ 0x02213230; symbol: func_ov031_02213230; size: 0x40.
extern "C" int GameState_InvokeHandlerOncePerMask(unsigned mask, unsigned value) {
    unsigned char* state = (unsigned char*)Network_GetConnectionWorkspace(1);
    unsigned char flags = state[8];
    if (flags & mask) return 0;
    state[8] = flags | mask;
    return ((int (*)(unsigned, unsigned))(*(unsigned*)state))(mask, value);
}
