#include <globaldefs.h>
ARM
extern "C" void *WfcUtility_LocalizeResourcePath(void *request);
extern "C" void *WfcUtility_LoadArchiveResource(void *source, unsigned *size, unsigned capacity);
extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void *address, unsigned size);
extern "C" void WfcUtility_FreeArchiveResourceAndReturnPoolEntry(void *resource);
// Original: arm9/ov031 @ 0x022234D8; symbol: func_ov031_022234d8; size: 0x40.
extern "C" void WfcUtility_LoadLocalizedResourceAndApply(void *request, void (*callback)(void *, int, unsigned)) {
    unsigned size;
    void *source = WfcUtility_LocalizeResourcePath(request);
    void *resource = WfcUtility_LoadArchiveResource(source, &size, 4);
    _Z25CleanInvalidateCacheRangePKvj(resource, size);
    callback(resource, 0, size);
    WfcUtility_FreeArchiveResourceAndReturnPoolEntry(resource);
}
