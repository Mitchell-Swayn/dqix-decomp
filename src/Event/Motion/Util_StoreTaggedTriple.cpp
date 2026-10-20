#include <globaldefs.h>
ARM
#include <std_library_functions.h>
extern "C" void* Pool_AppendFreeNode(void);
extern "C" void* memcpy(void* dst, const void* src, unsigned int length);
// Original: arm9/ov001 @ 0x0215A3F8; symbol: func_ov001_0215a3f8; size: 0x34.
extern "C" void Util_StoreTaggedTriple(void* object, unsigned a, unsigned b, unsigned c) {
    unsigned* dst = (unsigned*)Pool_AppendFreeNode();
    if (dst != 0) {
        dst[0] = 5;
        memcpy(dst + 1, &a, 12);
    }
}
