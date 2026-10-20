#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2111304; symbol: data_02111304.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned int OSInitThread_UnknownRoleZeroInitializedStorage_Variant2[];
extern "C" int System_WaitForBlockedListHead(void *, void *);
extern "C" int Ssl_ReadApplicationDataSpan(void *, void *);
extern "C" unsigned System_WaitForPendingResult(unsigned *, char *);
// Original: arm9/ov031 @ 0x0220357C; symbol: System_DispatchPendingRequestByTypeAndFlags; size: 0x64.
// Reads the pending request, routes types 10 and 11 to one handler, otherwise selects a handler from byte+9 or waits; clears output when no request exists.
extern "C" int System_DispatchPendingRequestByTypeAndFlags(unsigned *output) {
    void *root = *(void **)(OSInitThread_UnknownRoleZeroInitializedStorage_Variant2 + 1);
    unsigned char *request = (unsigned char *)*(void **)((unsigned char *)root + 0xa4);
    if (request != 0) {
        unsigned kind = (request[8] + 0xf6) & 0xff;
        if (kind <= 1)
            return System_WaitForBlockedListHead(output, request);
        if (request[9] != 0)
            return Ssl_ReadApplicationDataSpan(output, request);
        return System_WaitForPendingResult(output, (char *)request);
    }
    *output = 0;
    return 0;
}
