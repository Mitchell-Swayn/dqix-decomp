#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e5e8; symbol: data_ov031_0224e5e8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char* volatile NasAuthDestroySession_UnknownRoleZeroInitializedStorage[];
extern "C" void _Z9LockMutexP5Mutex(void*);
extern "C" void _Z11UnlockMutexP5Mutex(void*);
extern "C" void System_MarkStateReadyAndAwaitContext(void*);
extern "C" void _Z22AwaitContextCompletionP16ProcessorContext(void*);
// Original: arm9/ov031 @ 0x022169A0; symbol: func_ov031_022169a0; size: 0x8C.
extern "C" void System_StopSharedWorkerAndAwaitContext() {
 unsigned char* initial=NasAuthDestroySession_UnknownRoleZeroInitializedStorage[2];
 if(!initial) return;
 _Z9LockMutexP5Mutex(initial+0x13d8);
 *(int*)(NasAuthDestroySession_UnknownRoleZeroInitializedStorage[2]+0x13f0)=1;
 _Z11UnlockMutexP5Mutex(NasAuthDestroySession_UnknownRoleZeroInitializedStorage[2]+0x13d8);
 void* object=*(void**)(NasAuthDestroySession_UnknownRoleZeroInitializedStorage[2]+0x1314);
 if(object) System_MarkStateReadyAndAwaitContext(object);
 unsigned char* self=NasAuthDestroySession_UnknownRoleZeroInitializedStorage[2];
 if(*(int*)(self+0x1384)) _Z22AwaitContextCompletionP16ProcessorContext(self+0x1318);
}
