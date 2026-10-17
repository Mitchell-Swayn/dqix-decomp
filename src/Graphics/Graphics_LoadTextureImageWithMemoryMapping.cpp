#include <globaldefs.h>
#include <System/LoadToVRAM.h>
extern "C" {
// Original: arm9/main @ 0x020BB998; symbol: func_020bb998; size: 0x2C.
    void Graphics_LoadTextureImageWithMemoryMapping(const void *p,unsigned int offset,unsigned int len){
        MemoryMapTextureImage();
        LoadToTextureImage(p,offset,len);
        MemoryUnmapTextureImage();
    }
}
