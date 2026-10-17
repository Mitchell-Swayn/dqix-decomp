#include <globaldefs.h>
extern "C" char data_02110a28[]; extern "C" char* data_021103b0[2];extern "C" void _Z9LockMutexP5Mutex(void*);extern "C" void _Z11UnlockMutexP5Mutex(void*);extern "C" void ResourceEntry_UpdateIfActive(void*);extern "C" void InvokeActiveCallbackAndNotifyQueues(void*);
struct Job{char pad[0x110];signed int callbackEnabled:1; signed int cleanupEnabled:1;unsigned reserved:30;char rest[0x5c];void(*callback)(Job*);};
// Original: arm9/main @ 0x020BF1A0; symbol: func_020bf1a0; size: 0x98.
extern "C" ARM void ResourceJob_RunCallbacksUnderMutexes(Job* job){_Z9LockMutexP5Mutex(data_02110a28);if(data_021103b0[1])_Z9LockMutexP5Mutex(data_021103b0[1]+0x4c8);if(job->cleanupEnabled)ResourceEntry_UpdateIfActive(job);if(job->callbackEnabled)job->callback(job);InvokeActiveCallbackAndNotifyQueues(job);_Z11UnlockMutexP5Mutex(data_02110a28);if(!data_021103b0[1])return;_Z11UnlockMutexP5Mutex(data_021103b0[1]+0x4c8);}
