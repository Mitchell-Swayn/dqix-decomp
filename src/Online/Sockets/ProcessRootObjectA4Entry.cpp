#include <globaldefs.h>
ARM
extern "C" void Ssl_SendCloseNotify(void*);
extern "C" void System_UpdatePriorityContextState(void*);
// Original data: arm9/main @ 0x2111304; symbol: data_02111304.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned int OSInitThread_UnknownRoleZeroInitializedStorage_Variant2[];
// Original: arm9/ov031 @ 0x022033E8; symbol: ProcessRootObjectA4Entry; size: 0x3C.
// Follows the shared root to its +0xA4 object; when present, conditionally calls one helper for byte +9 and always calls the next helper.
extern "C" void ProcessRootObjectA4Entry(void) {
    void* root = (void*)OSInitThread_UnknownRoleZeroInitializedStorage_Variant2[1];
    void* object = *(void**)((char*)root + 0xA4);
    if (object == 0) return;
    if (*(unsigned char*)((char*)object + 9) != 0)
        Ssl_SendCloseNotify(object);
    System_UpdatePriorityContextState(object);
}
