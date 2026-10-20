#include <globaldefs.h>
ARM
extern "C" int GlobalState_IsCurrentObjectFieldSeven(void);
extern "C" void System_SetSharedStateUnlessTwoUnderMutex(unsigned int);
extern "C" void _Z19BlockCurrentContextP18BlockedContextList(void *);
// Original data: arm9/ov031 @ 0x224e588; symbol: data_ov031_0224e588.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char *YssdClientRunWorker_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x022102C8; symbol: System_BlockContextUntilReady; size: 0x4C.
// Returns zero when the shared context is absent; otherwise, when not ready, sets state 1 and blocks the current context before returning the updated readiness value.
extern "C" int System_BlockContextUntilReady(void) {
 if (!YssdClientRunWorker_UnknownRoleZeroInitializedStorage) return 0;
 if (!GlobalState_IsCurrentObjectFieldSeven()) {
  System_SetSharedStateUnlessTwoUnderMutex(1);
  _Z19BlockCurrentContextP18BlockedContextList(YssdClientRunWorker_UnknownRoleZeroInitializedStorage + 0xa04);
 }
 return GlobalState_IsCurrentObjectFieldSeven();
}
