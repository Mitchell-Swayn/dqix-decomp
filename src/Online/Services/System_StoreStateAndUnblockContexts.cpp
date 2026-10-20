#include <globaldefs.h>
ARM
extern "C" void System_SetSharedStateUnlessTwoUnderMutex(unsigned int);
extern "C" void YssdClient_SetWorkerPhase(unsigned int);
extern "C" void _Z15UnblockContextsP18BlockedContextList(void *);
// Original data: arm9/ov031 @ 0x224e588; symbol: data_ov031_0224e588.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char *YssdClientRunWorker_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x022103F8; symbol: System_StoreStateAndUnblockContexts; size: 0x34.
// Resets context state, stores the supplied indirect word, then unblocks contexts at shared list+0xa04.
extern "C" void System_StoreStateAndUnblockContexts(unsigned int value) {
 System_SetSharedStateUnlessTwoUnderMutex(0);
 YssdClient_SetWorkerPhase(value);
 _Z15UnblockContextsP18BlockedContextList(YssdClientRunWorker_UnknownRoleZeroInitializedStorage + 0xa04);
}
