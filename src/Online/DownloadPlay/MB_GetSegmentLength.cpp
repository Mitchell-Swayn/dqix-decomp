#include <globaldefs.h>
#include <Filesystem/FileAccessor.h>
#include <Filesystem/NitroVM.h>
ARM
// Original: arm9/ov027 @ 0x021D9E1C; symbol: func_ov027_021d9e1c; size: 0x80.
// Calculates the multiboot segment allocation from a file header or the boot ROM header.
extern "C" unsigned MB_GetSegmentLength(NitroVM *vm)
{
    unsigned *header=0;
    unsigned length=0;
    unsigned buffer[24];
    if(vm) {
        int position=*(unsigned*)((char*)vm+0x2c)-*(unsigned*)((char*)vm+0x24);
        if((unsigned)NitroVM_ReadSync(vm,buffer,96)>=96) header=buffer;
        NitroVM_Seek(vm,position,0);
    } else header=(unsigned*)0x027ffe00;
    if(header) {
        length=header[11]+0x268+header[15];
        if(length<0x10000) length=0x10000;
    }
    return length;
}
