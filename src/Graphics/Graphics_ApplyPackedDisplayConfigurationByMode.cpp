#include <globaldefs.h>
#include <System/Cache.h>
#include <System/LoadToVRAM.h>

extern "C" void NNS_G2dSetImageLocation(void*, int, void*, unsigned int);

// Original: arm9/main @ 0x020B0594; symbol: func_020b0594; size: 0x22C.
extern "C" ARM void Graphics_ApplyPackedDisplayConfigurationByMode(unsigned short* input, void* destination, int mode, void* record)
{
    unsigned int registerFlags = *(volatile unsigned int*)((char*)input + 8);
    if (mode != 0) {
        switch (mode) {
        case 1:
            *(volatile unsigned int*)0x04000000 =
                (*(volatile unsigned int*)0x04000000 & 0xffcfffefu) | registerFlags;
            break;
        case 2:
            *(volatile unsigned int*)0x04001000 =
                (*(volatile unsigned int*)0x04001000 & 0xffcfffefu) | registerFlags;
            break;
        default:
            break;
        }
    }

    CleanInvalidateCacheRange(*(void**)((char*)input + 0x14), *(unsigned int*)((char*)input + 0x10));
    switch (mode) {
    case 0:
        MemoryMapTextureImage();
        LoadToTextureImage(*(void**)((char*)input + 0x14), (unsigned int)destination, *(unsigned int*)((char*)input + 0x10));
        MemoryUnmapTextureImage();
        break;
    case 1:
        LoadToMainObjVRAM(*(void**)((char*)input + 0x14), (unsigned int)destination, *(unsigned int*)((char*)input + 0x10));
        break;
    case 2:
        LoadToSubObjVRAM(*(void**)((char*)input + 0x14), (unsigned int)destination, *(unsigned int*)((char*)input + 0x10));
        break;
    default:
        break;
    }

    if (*(unsigned int*)((char*)input + 8) == 0) {
        int decoded;
        switch (input[1]) {
        case 1: decoded=0; break;
        case 2: decoded=1; break;
        case 4: decoded=2; break;
        case 8: decoded=3; break;
        case 16: decoded=4; break;
        case 32: decoded=5; break;
        default: decoded=0; break;
        }
        *(unsigned int*)((char*)record + 0x0c)=decoded;
        switch (input[0]) {
        case 1: decoded=0; break;
        case 2: decoded=1; break;
        case 4: decoded=2; break;
        case 8: decoded=3; break;
        case 16: decoded=4; break;
        case 32: decoded=5; break;
        default: decoded=0; break;
        }
        *(unsigned int*)((char*)record + 0x10)=decoded;
    } else {
        *(unsigned int*)((char*)record + 0x0c)=input[1];
        *(unsigned int*)((char*)record + 0x10)=input[0];
    }
    *(unsigned int*)((char*)record + 0x14) = *(unsigned int*)((char*)input + 4);
    *(unsigned int*)((char*)record + 0x18) = 0;
    *(unsigned int*)((char*)record + 0x1c) = 1;
    unsigned int flags=*(unsigned int*)((char*)input + 8);
    *(unsigned int*)((char*)record + 0x20) = flags;
    NNS_G2dSetImageLocation(record, mode, destination, flags);
}
