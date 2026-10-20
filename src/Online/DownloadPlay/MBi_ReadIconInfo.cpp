#include <globaldefs.h>
#include <Filesystem/FileAccessor.h>
#include <Filesystem/NitroVM.h>
#include <Filesystem/LowNitroHandle.h>
ARM
// Original: arm9/ov027 @ 0x021DAC74; symbol: func_ov027_021dac74; size: 0xA0.
// Reads the 32-byte palette or 512-byte icon from a file with exactly that length.
extern "C" int MBi_ReadIconInfo(const char *path,unsigned char *destination,int pixels)
{
    unsigned length=pixels?512:32;
    if(pixels) destination+=32;
    if(!path) return 0;
    NitroVM vm;
    NitroVM_Initialize(&vm);
    if(!NitroVM_PrepareReadFileByPath(&vm,path)) return 0;
    if(length!=*(unsigned*)((char*)&vm+0x28)-*(unsigned*)((char*)&vm+0x24)) {
        NitroVM_FinishRead(&vm); return 0;
    }
    NitroVM_ReadSync(&vm,destination,length);
    NitroVM_FinishRead(&vm);
    return 1;
}
