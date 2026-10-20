#include <globaldefs.h>
ARM
extern "C" void MapVRAMBanksToLCDC(int banks);
extern "C" unsigned int DisableLCDCMappedVRAMBanks();
extern "C" void MIi_CpuClearFast(int value, void* dst, unsigned int len);
// Original: arm9/ov031 @ 0x0223DF4C; symbol: func_ov031_0223df4c; size: 0x84.
extern "C" void Graphics_ClearVramOamAndPalettes() {
    MapVRAMBanksToLCDC(0x1f3);
    MIi_CpuClearFast(0, (void*)0x6800000, 0x40000);
    MIi_CpuClearFast(0, (void*)0x6880000, 0x24000);
    DisableLCDCMappedVRAMBanks();
    MIi_CpuClearFast(0x200, (void*)0x7000000, 0x400);
    MIi_CpuClearFast(0, (void*)0x5000000, 0x400);
    MIi_CpuClearFast(0x200, (void*)0x7000400, 0x400);
    MIi_CpuClearFast(0, (void*)0x5000400, 0x400);
}
