#include <globaldefs.h>
ARM

extern "C" unsigned int Util_CountStringBytesViaSharedRoutine(const char *);
extern "C" void Memory_Copy8(char *dst, const char *src, unsigned int length);
// Original data: arm9/ov031 @ 0x2290da0; symbol: data_ov031_02290da0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char DlcDownloadShutdownClient_UnknownRoleZeroInitializedStorage[];

// Original: arm9/ov031 @ 0x0223E674; symbol: func_ov031_0223e674; size: 0x4C.
extern "C" char *Unclassified_AllocateAndCopyString(const char *source) {
    unsigned int length = Util_CountStringBytesViaSharedRoutine(source);
    char *result = ((char *(*)(unsigned int, unsigned int))(*(void **)(DlcDownloadShutdownClient_UnknownRoleZeroInitializedStorage + 0xc)))(length + 1, 4);
    if (result != 0) {
        Memory_Copy8(result, source, length);
        result[length] = 0;
    }
    return result;
}
