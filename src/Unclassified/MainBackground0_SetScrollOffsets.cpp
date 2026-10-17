#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x0204A804; symbol: func_0204a804; size: 0x28.
    void MainBackground0_SetScrollOffsets(unsigned int x,unsigned int y){
        unsigned int mask=511;
        unsigned int high=mask<<16;
        *(volatile unsigned int *)0x04000010=(x&mask)|((y<<16)&high);
    }
}
