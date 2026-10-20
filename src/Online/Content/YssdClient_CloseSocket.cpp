#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e588; symbol: data_ov031_0224e588.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char* YssdClientRunWorker_UnknownRoleZeroInitializedStorage;
extern "C" void _Z9LockMutexP5Mutex(void*);
extern "C" void _Z11UnlockMutexP5Mutex(void*);
extern "C" int NetworkSocket_Close(int);
extern "C" void Overlay_EnsureContextStateTwoUnlessAlreadySet(int,int);
extern "C" void _Z19SleepCurrentContextj(unsigned);
extern "C" void YssdClient_SetWorkerPhase(int);
// Original: arm9/ov031 @ 0x02210B4C; symbol: System_PollPendingHandleAndRecordCompletion; size: 0xa0.
// Claims pending handle under mutex and polls result -26 until completion, reporting errors and state1.
extern "C" void YssdClient_CloseSocket() {
 int handle=*(int*)(YssdClientRunWorker_UnknownRoleZeroInitializedStorage+0x1b8);_Z9LockMutexP5Mutex(YssdClientRunWorker_UnknownRoleZeroInitializedStorage+0x1bc);*(int*)(YssdClientRunWorker_UnknownRoleZeroInitializedStorage+0x1b8)=-59;_Z11UnlockMutexP5Mutex(YssdClientRunWorker_UnknownRoleZeroInitializedStorage+0x1bc);
 if(handle>=0){if(NetworkSocket_Close(handle)<0)Overlay_EnsureContextStateTwoUnlessAlreadySet(5,-50);else{int result;do{_Z19SleepCurrentContextj(100);result=NetworkSocket_Close(handle);}while(result==-26);if(result!=0)Overlay_EnsureContextStateTwoUnlessAlreadySet(5,-50);}}
 YssdClient_SetWorkerPhase(1);
}
