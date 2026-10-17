#include <globaldefs.h>
ARM
extern "C" unsigned char* volatile data_ov031_0224e5e8[];
extern "C" void _Z9LockMutexP5Mutex(void*);
extern "C" void _Z11UnlockMutexP5Mutex(void*);
extern "C" void System_MarkStateReadyAndAwaitContext(void*);
extern "C" void _Z22AwaitContextCompletionP16ProcessorContext(void*);
// Original: arm9/ov031 @ 0x022169A0; symbol: func_ov031_022169a0; size: 0x8C.
extern "C" void System_StopSharedWorkerAndAwaitContext() {
 unsigned char* initial=data_ov031_0224e5e8[2];
 if(!initial) return;
 _Z9LockMutexP5Mutex(initial+0x13d8);
 *(int*)(data_ov031_0224e5e8[2]+0x13f0)=1;
 _Z11UnlockMutexP5Mutex(data_ov031_0224e5e8[2]+0x13d8);
 void* object=*(void**)(data_ov031_0224e5e8[2]+0x1314);
 if(object) System_MarkStateReadyAndAwaitContext(object);
 unsigned char* self=data_ov031_0224e5e8[2];
 if(*(int*)(self+0x1384)) _Z22AwaitContextCompletionP16ProcessorContext(self+0x1318);
}
