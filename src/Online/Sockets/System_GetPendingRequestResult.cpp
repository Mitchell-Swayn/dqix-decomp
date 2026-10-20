#include <globaldefs.h>
ARM
extern "C" int Ssl_GetAvailableApplicationDataLength(void*);
// Original data: arm9/main @ 0x2111304; symbol: data_02111304.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned int OSInitThread_UnknownRoleZeroInitializedStorage_Variant2[];
// Original: arm9/ov031 @ 0x02203B1C; symbol: System_GetPendingRequestResult; size: 0x70.
// Returns the current request result when valid, delegates to the alternate handler when byte+9 is set, returns zero for no request, and -1 for invalid types.
extern "C" int System_GetPendingRequestResult(void) {
    void* object = *(void**)((char*)OSInitThread_UnknownRoleZeroInitializedStorage_Variant2[1] + 0xA4);
    if (object == 0) goto no_object;
    if (*(unsigned char*)((char*)object + 9) != 0)
        return Ssl_GetAvailableApplicationDataLength(object);
    int value = *(int*)((char*)object + 0x44);
    if (value != 0) goto return_value;
    unsigned char state = *(unsigned char*)((char*)object + 8);
    if (state == 4) goto return_value;
    if ((unsigned char)(state + 0xF6) > 1) goto invalid;
return_value:
    return value;
invalid:
    return -1;
no_object:
    return 0;
}
