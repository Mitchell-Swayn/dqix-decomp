#include <globaldefs.h>
#include <System/DMA.h>
#include <System/LoadToVRAM.h>
extern "C" unsigned char data_021052b4[];
extern "C" unsigned char data_021056b4[];
// Original: arm9/main @ 0x0203BDB0; symbol: func_0203bdb0; size: 0x90.
extern "C" void Graphics_LoadAndClearEnabledOamScreens(unsigned char* state) {
    if (state[0xc] != 0) {
        LoadToMainOAM(data_021052b4, 0, 0x400);
        DMAMemsetSynchronous(3, (unsigned int)data_021052b4, 0xc0, 0x400);
    }
    if (state[0xd] != 0) {
        LoadToSubOAM(data_021056b4, 0, 0x400);
        DMAMemsetSynchronous(3, (unsigned int)data_021056b4, 0xc0, 0x400);
    }
    if (state[0xc] != 0 || state[0xd] != 0) *(unsigned short*)(state + 0x520) = 4;
}
