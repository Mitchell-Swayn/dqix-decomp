#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void func_020ca50c(const void *,volatile void *);
// Original: arm9/main @ 0x020C5574; symbol: func_020c5574; size: 0x14.
    void Geometry_SetEdgeColorTable(const void *p){
        func_020ca50c(p,(volatile void *)0x04000360);
    }
}
