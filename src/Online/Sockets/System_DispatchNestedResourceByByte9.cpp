#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2111304; symbol: data_02111304.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char OSInitThread_UnknownRoleZeroInitializedStorage_Variant2;
extern "C" int Ssl_InitializeAndRunClientHandshake(void*);
extern "C" int Network_ConnectTcpSocketWithRetries(void*);
// Original: arm9/ov031 @ 0x02203358; symbol: System_DispatchNestedResourceByByte9; size: 0x40.
// Dispatches the nested resource to one of two handlers based on byte+9; absent resource returns 1.
extern "C" int System_DispatchNestedResourceByByte9() {
    unsigned char* object = *(unsigned char**)((char*)&OSInitThread_UnknownRoleZeroInitializedStorage_Variant2 + 4);
    void* resource = *(void**)(object + 0xa4);
    if (resource) {
        if (*(unsigned char*)((char*)resource + 9)) return Ssl_InitializeAndRunClientHandshake(resource);
        return Network_ConnectTcpSocketWithRetries(resource);
    }
    return 1;
}
