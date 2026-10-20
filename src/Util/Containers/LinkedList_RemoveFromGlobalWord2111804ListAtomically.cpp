#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
// Original data: arm9/main @ 0x2111804; symbol: data_02111804.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern void *PowerManagementPrependSleepCallback_UnknownRoleZeroInitializedStorage;
    void LinkedList_RemoveNodeByIdentityWithIRQGuard(void **,void *);
// Original: arm9/main @ 0x020CEF64; symbol: func_020cef64; size: 0x18.
    void LinkedList_RemoveFromGlobalWord2111804ListAtomically(void *p){
        LinkedList_RemoveNodeByIdentityWithIRQGuard(&PowerManagementPrependSleepCallback_UnknownRoleZeroInitializedStorage,p);
    }
}
