#include <globaldefs.h>
#include <System/Mutex.h>
ARM
// Original data: arm9/ov031 @ 0x224e588; symbol: data_ov031_0224e588.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void* YssdClientRunWorker_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0221038C; symbol: func_ov031_0221038c; size: 0x50.
extern "C" void System_SetSharedStateUnlessTwoUnderMutex(int value) {
 if(!YssdClientRunWorker_UnknownRoleZeroInitializedStorage) return;
 unsigned char* state=(unsigned char*)YssdClientRunWorker_UnknownRoleZeroInitializedStorage;
 Mutex* mutex=(Mutex*)(state+8);
 (void)*(volatile int*)(state+4);
 LockMutex(mutex);
 if(*(int*)((unsigned char*)YssdClientRunWorker_UnknownRoleZeroInitializedStorage+4)!=2)
  *(int*)((unsigned char*)YssdClientRunWorker_UnknownRoleZeroInitializedStorage+4)=value;
 UnlockMutex((Mutex*)((unsigned char*)YssdClientRunWorker_UnknownRoleZeroInitializedStorage+8));
}
