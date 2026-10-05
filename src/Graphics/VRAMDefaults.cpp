#include "Graphics/VRAMAllocations.h"

// Until a VRAM allocator is installed, allocation fails with key zero and
// freeing a key reports failure. These are the original SDK default hooks.
extern "C" unsigned int DefaultTextureImageAllocate(unsigned int, unsigned int, unsigned int)
{
    return 0;
}
extern "C" int DefaultTextureImageFree(unsigned int)
{
    return -1;
}
extern "C" unsigned int DefaultTexturePaletteAllocate(unsigned int, unsigned int, unsigned int)
{
    return 0;
}
extern "C" int DefaultTexturePaletteFree(unsigned int)
{
    return -1;
}

TextureVRAMAllocateCallback data_020f1ee8 = DefaultTextureImageAllocate;
TextureVRAMFreeCallback data_020f1eec = DefaultTextureImageFree;
TextureVRAMAllocateCallback data_020f1ef0 = DefaultTexturePaletteAllocate;
TextureVRAMFreeCallback data_020f1ef4 = DefaultTexturePaletteFree;
