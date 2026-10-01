// Until a VRAM allocator is installed, allocation fails with key zero and
// freeing a key reports failure. These are the original SDK default hooks.
extern "C" unsigned int DefaultTextureImageAllocate(unsigned int, bool, unsigned int)
{
    return 0;
}
extern "C" int DefaultTextureImageFree(unsigned int)
{
    return -1;
}
extern "C" unsigned int DefaultTexturePaletteAllocate(unsigned int, bool, unsigned int)
{
    return 0;
}
extern "C" int DefaultTexturePaletteFree(unsigned int)
{
    return -1;
}
