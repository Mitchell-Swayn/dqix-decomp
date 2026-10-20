#include <globaldefs.h>
#include <System/LoadToVRAM.h>
extern "C" {
// Original: arm9/main @ 0x020BBAF4; symbol: func_020bbaf4; size: 0x2C.
    void Object_InvokeMemoryMapMainBGExtendedPalette(const void *p,unsigned int offset,unsigned int len){
        MemoryMapMainBGExtendedPalette();
        LoadToMainBGExtendedPalette(p,offset,len);
        MemoryUnmapMainBGExtendedPalette();
    }
}
