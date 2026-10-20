#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void MI_Copy32B(const void *,volatile void *);
// Original: arm9/main @ 0x020C5574; symbol: func_020c5574; size: 0x14.
    void Geometry_SetEdgeColorTable(const void *p){
        MI_Copy32B(p,(volatile void *)0x04000360);
    }
}
