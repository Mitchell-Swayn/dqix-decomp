#include <globaldefs.h>
#include <System/LoadToVRAM.h>
ARM
#pragma optimization_level 4
extern "C" {
// Original: arm9/main @ 0x020BBBB0; symbol: func_020bbbb0; size: 0xC.
    void Graphics_ForwardSubObjectPaletteLoad(const void *p,unsigned int offset,unsigned int len){
        LoadToSubObjStandardPalette(p,offset,len);
    }
}
