#include <globaldefs.h>
ARM
typedef void (*OverlayCallback)(void*);
// Original data: arm9/ov031 @ 0x2290fc8; symbol: data_ov031_02290fc8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" OverlayCallback HttpDestroyRequest_UnknownRoleZeroInitializedStorage[1];
extern "C" void Http_FreeCircularParameterList(void*);
// Original: arm9/ov031 @ 0x02240E70; symbol: func_ov031_02240e70; size: 0x78.
extern "C" int Http_DestroyRequest(unsigned char* object) {
    Http_FreeCircularParameterList(*(void**)(object + 0x34));
    Http_FreeCircularParameterList(*(void**)(object + 0x38));
    volatile void** fields = (volatile void**)object;
    if (fields[8]) {
        void* nested = *(void**)((char*)fields[8] + 0x800);
        if (nested)
            HttpDestroyRequest_UnknownRoleZeroInitializedStorage[0](nested);
        HttpDestroyRequest_UnknownRoleZeroInitializedStorage[0]((void*)fields[8]);
    }
    HttpDestroyRequest_UnknownRoleZeroInitializedStorage[0]((void*)fields[9]);
    HttpDestroyRequest_UnknownRoleZeroInitializedStorage[0](object);
    return 1;
}
