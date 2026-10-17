#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void MI_Copy36B(const void *,void *);
// Original: arm9/main @ 0x020C51C0; symbol: func_020c51c0; size: 0x1C.
    void Graphics_WriteGeometryCommand26AndDataBlock(const void *src){
        *(volatile unsigned int *)0x04000400=26;
        MI_Copy36B(src,(void *)0x04000400);
    }
}
