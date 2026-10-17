#include "Graphics/VRAMAllocations.h"

// Until a VRAM allocator is installed, allocation fails with key zero and
// freeing a key reports failure. These are the original SDK default hooks.
// Original: arm9/main @ 0x020BB424; symbol: DefaultTextureImageAllocate; size: 0x8.
extern "C" unsigned int DefaultTextureImageAllocate(unsigned int, unsigned int, unsigned int)
{
    return 0;
}
// Original: arm9/main @ 0x020BB42C; symbol: DefaultTextureImageFree; size: 0x8.
extern "C" int DefaultTextureImageFree(unsigned int)
{
    return -1;
}
// Original: arm9/main @ 0x020BB434; symbol: DefaultTexturePaletteAllocate; size: 0x8.
extern "C" unsigned int DefaultTexturePaletteAllocate(unsigned int, unsigned int, unsigned int)
{
    return 0;
}
// Original: arm9/main @ 0x020BB43C; symbol: DefaultTexturePaletteFree; size: 0x8.
extern "C" int DefaultTexturePaletteFree(unsigned int)
{
    return -1;
}

TextureVRAMAllocateCallback data_020f1ee8 = DefaultTextureImageAllocate;
TextureVRAMFreeCallback data_020f1eec = DefaultTextureImageFree;
TextureVRAMAllocateCallback data_020f1ef0 = DefaultTexturePaletteAllocate;
TextureVRAMFreeCallback data_020f1ef4 = DefaultTexturePaletteFree;
