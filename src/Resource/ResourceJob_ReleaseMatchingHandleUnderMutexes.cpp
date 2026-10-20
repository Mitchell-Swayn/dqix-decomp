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
extern "C" char ResourceJobRunCallbacksUnderMutexes_UnknownRoleZeroInitializedStorage[];extern "C" char* NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage[2];extern "C" void _Z9LockMutexP5Mutex(void*);extern "C" void _Z11UnlockMutexP5Mutex(void*);extern "C" void ResourceJob_RunCallbacksUnderMutexes(void*);extern "C" void NNS_SndStrmFreeChannel(void*);struct Job{char pad[0x120];int count;unsigned char state;char gap[7];void* handle;int result;};
#pragma optimization_level 4
// Original: arm9/main @ 0x020BF484; symbol: func_020bf484; size: 0x9C.
extern "C" ARM void ResourceJob_ReleaseMatchingHandleUnderMutexes(void* handle,int ignored,Job* p){if(handle!=p->handle)return;_Z9LockMutexP5Mutex(ResourceJobRunCallbacksUnderMutexes_UnknownRoleZeroInitializedStorage);if(NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage[1])_Z9LockMutexP5Mutex(NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage[1]+0x4c8);ResourceJob_RunCallbacksUnderMutexes(p);p->handle=0;p->result=0;p->state=0;if(p->count>0){NNS_SndStrmFreeChannel(p);p->count=0;}_Z11UnlockMutexP5Mutex(ResourceJobRunCallbacksUnderMutexes_UnknownRoleZeroInitializedStorage);if(!NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage[1])return;_Z11UnlockMutexP5Mutex(NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage[1]+0x4c8);}
