#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void MIi_CpuCopy16(const void *,volatile void *,int);
// Original: arm9/main @ 0x020C555C; symbol: func_020c555c; size: 0x18.
    void Graphics_CopySixteenBytesToEdgeColorRegisters(const void *p){
        MIi_CpuCopy16(p,(volatile void *)0x04000330,16);
    }
}
