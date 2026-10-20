#include <globaldefs.h>

// Original data: arm9/main @ 0x2107800; symbol: data_02107800.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned int TextContextGetSharedInstance_UnknownRoleZeroInitializedStorage[];
extern "C" void TextCanvas_BlitMasked4bppPixels(void*, void*, int, int, int, int, int, int);

// Original: arm9/main @ 0x020435A8; symbol: func_020435a8; size: 0x58.
extern "C" void WindowFrame_BlitSharedBorderTile(void* object, int arg1, int arg2, int index)
{
    if (object != 0) {
        volatile unsigned int* shared = (volatile unsigned int*)TextContextGetSharedInstance_UnknownRoleZeroInitializedStorage;
        int base = shared[1];
        TextCanvas_BlitMasked4bppPixels(object, (char*)base + index * 32,
                      arg1, arg2, 8, 8, 0xf0, 0xf);
    }
}
