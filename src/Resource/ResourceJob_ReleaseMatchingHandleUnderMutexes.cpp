#include <globaldefs.h>
extern "C" char data_02110a28[];extern "C" char* data_021103b0[2];extern "C" void _Z9LockMutexP5Mutex(void*);extern "C" void _Z11UnlockMutexP5Mutex(void*);extern "C" void ResourceJob_RunCallbacksUnderMutexes(void*);extern "C" void ReleasePresentDataAndClearSize(void*);struct Job{char pad[0x120];int count;unsigned char state;char gap[7];void* handle;int result;};
#pragma optimization_level 4
// Original: arm9/main @ 0x020BF484; symbol: func_020bf484; size: 0x9C.
extern "C" ARM void ResourceJob_ReleaseMatchingHandleUnderMutexes(void* handle,int ignored,Job* p){if(handle!=p->handle)return;_Z9LockMutexP5Mutex(data_02110a28);if(data_021103b0[1])_Z9LockMutexP5Mutex(data_021103b0[1]+0x4c8);ResourceJob_RunCallbacksUnderMutexes(p);p->handle=0;p->result=0;p->state=0;if(p->count>0){ReleasePresentDataAndClearSize(p);p->count=0;}_Z11UnlockMutexP5Mutex(data_02110a28);if(!data_021103b0[1])return;_Z11UnlockMutexP5Mutex(data_021103b0[1]+0x4c8);}
