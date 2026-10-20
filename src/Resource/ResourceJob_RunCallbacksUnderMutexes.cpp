#include <globaldefs.h>
// Original data: arm9/main @ 0x21103b0; symbol: data_021103b0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2110a28; symbol: data_02110a28.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char ResourceJobRunCallbacksUnderMutexes_UnknownRoleZeroInitializedStorage[]; extern "C" char* NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage[2];extern "C" void _Z9LockMutexP5Mutex(void*);extern "C" void _Z11UnlockMutexP5Mutex(void*);extern "C" void ResourceEntry_UpdateIfActive(void*);extern "C" void SoundStream_FinalizePlayerAndCancelRequests(void*);
struct Job{char pad[0x110];signed int callbackEnabled:1; signed int cleanupEnabled:1;unsigned reserved:30;char rest[0x5c];void(*callback)(Job*);};
// Original: arm9/main @ 0x020BF1A0; symbol: func_020bf1a0; size: 0x98.
extern "C" ARM void ResourceJob_RunCallbacksUnderMutexes(Job* job){_Z9LockMutexP5Mutex(ResourceJobRunCallbacksUnderMutexes_UnknownRoleZeroInitializedStorage);if(NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage[1])_Z9LockMutexP5Mutex(NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage[1]+0x4c8);if(job->cleanupEnabled)ResourceEntry_UpdateIfActive(job);if(job->callbackEnabled)job->callback(job);SoundStream_FinalizePlayerAndCancelRequests(job);_Z11UnlockMutexP5Mutex(ResourceJobRunCallbacksUnderMutexes_UnknownRoleZeroInitializedStorage);if(!NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage[1])return;_Z11UnlockMutexP5Mutex(NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage[1]+0x4c8);}
