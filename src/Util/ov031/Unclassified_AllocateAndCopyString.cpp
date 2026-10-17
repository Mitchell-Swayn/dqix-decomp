#include <globaldefs.h>
ARM

extern "C" unsigned int func_ov031_0223fb48(const char *);
extern "C" void Memory_Copy8(char *dst, const char *src, unsigned int length);
extern "C" unsigned char data_ov031_02290da0[];

// Original: arm9/ov031 @ 0x0223E674; symbol: func_ov031_0223e674; size: 0x4C.
extern "C" char *Unclassified_AllocateAndCopyString(const char *source) {
    unsigned int length = func_ov031_0223fb48(source);
    char *result = ((char *(*)(unsigned int, unsigned int))(*(void **)(data_ov031_02290da0 + 0xc)))(length + 1, 4);
    if (result != 0) {
        Memory_Copy8(result, source, length);
        result[length] = 0;
    }
    return result;
}
