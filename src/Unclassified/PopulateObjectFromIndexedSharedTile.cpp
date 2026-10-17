#include <globaldefs.h>

extern unsigned int data_02107800[];
extern "C" void TextCanvas_BlitMasked4bppPixels(void*, void*, int, int, int, int, int, int);

// Original: arm9/main @ 0x020435A8; symbol: func_020435a8; size: 0x58.
extern "C" void PopulateObjectFromIndexedSharedTile(void* object, int arg1, int arg2, int index)
{
    if (object != 0) {
        volatile unsigned int* shared = (volatile unsigned int*)data_02107800;
        int base = shared[1];
        TextCanvas_BlitMasked4bppPixels(object, (char*)base + index * 32,
                      arg1, arg2, 8, 8, 0xf0, 0xf);
    }
}
