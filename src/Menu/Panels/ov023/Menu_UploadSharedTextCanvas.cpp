#include <globaldefs.h>
#include <System/LoadToVRAM.h>
#include <System/Cache.h>
ARM
extern "C" unsigned Graphics_GetSelectedBackgroundScreenBase(int, int);
extern "C" unsigned char MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov023 @ 0x021DDC98; symbol: Menu_UploadSharedTextCanvas; size: 0x168.
// Transfers canvas character tiles and writes sequential tile indices and palette bits to its background rectangle.
extern "C" unsigned Menu_UploadSharedTextCanvas(char* canvas, unsigned offset, unsigned short palette, int layer) {
    unsigned size = 0;
    if (*(void**)(MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage+4) && canvas) {
        short width = *(short*)(canvas+0xa8);
        short height = *(short*)(canvas+0xaa);
        unsigned short tile;
        int mode = *(signed char*)(*(char**)(MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage+0x20)+0x77c);
        size = width * height * 32;
        short x = *(short*)(canvas+0xac);
        int y = *(short*)(canvas+0xae);
        if (mode == 1) {
            CleanInvalidateCacheRange(*(void**)(MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage+4),size);
            LoadToSubBG0CharacterData(*(void**)(MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage+4),offset,size);
        } else {
            CleanInvalidateCacheRange(*(void**)(MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage+4),size);
            if (layer) LoadToMainBG1CharacterData(*(void**)(MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage+4),offset,size);
            else LoadToMainBG2CharacterData(*(void**)(MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage+4),offset,size);
        }
        tile = offset >> 5;
        unsigned base = Graphics_GetSelectedBackgroundScreenBase(mode,layer);
        if (base) {
            for (short row=0; row<height; ++y,++row) {
                unsigned short* dest = (unsigned short*)(base + y*64 + x*2);
                for (short col=0; col<width; ++col) {
                    unsigned short entry = tile;
                    entry |= palette << 12;
                    CleanInvalidateCacheRange(&entry,2);
                    *dest++ = entry;
                    ++tile;
                }
            }
        }
    }
    return size;
}
