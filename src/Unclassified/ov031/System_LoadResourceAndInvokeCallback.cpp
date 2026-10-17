#include <globaldefs.h>
ARM
extern "C" void *Unclassified_CopyStringAndNormalizeMarker(void *request);
extern "C" void *func_ov031_0223b61c(void *source, unsigned *size, unsigned capacity);
extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void *address, unsigned size);
extern "C" void Unclassified_FreeArgumentAndUpdateGlobalOwner(void *resource);
// Original: arm9/ov031 @ 0x022234D8; symbol: func_ov031_022234d8; size: 0x40.
extern "C" void System_LoadResourceAndInvokeCallback(void *request, void (*callback)(void *, int, unsigned)) {
    unsigned size;
    void *source = Unclassified_CopyStringAndNormalizeMarker(request);
    void *resource = func_ov031_0223b61c(source, &size, 4);
    _Z25CleanInvalidateCacheRangePKvj(resource, size);
    callback(resource, 0, size);
    Unclassified_FreeArgumentAndUpdateGlobalOwner(resource);
}
