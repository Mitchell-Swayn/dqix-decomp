#include <globaldefs.h>
ARM
extern "C" void ProcessRootObjectA4Entry();
extern "C" void WaitForPendingFlagWithTimeout();
extern "C" void Network_DeactivateCurrentThreadSocket();
extern "C" void Network_DetachSocketFromCurrentThread();
extern "C" int System_SendMessageWithOverlayFallback(void*,void*);
extern "C" int _Z20DisableIRQInterruptsv();
extern "C" void System_AppendCallbackToGlobalList(void*);
extern "C" void Network_RegisterClosedSocket(void*);
extern "C" int _Z20SetIRQInterruptStatei(int);
extern "C" void _Z22AwaitContextCompletionP16ProcessorContext(void*);
// Original: arm9/ov031 @ 0x022069D0; symbol: System_StopCallbackContextAndMarkCompletion; size: 0x98.
extern "C" int Network_ExecuteSocketClose(char* object) {
 char* state=*(char**)(object+4);int ready=1;int kind=*(signed char*)(state+0x73);if(kind!=0 && kind!=4)ready=0;
 if(ready){_Z22AwaitContextCompletionP16ProcessorContext(*(char**)(state+0x68)+32);ProcessRootObjectA4Entry();WaitForPendingFlagWithTimeout();Network_DeactivateCurrentThreadSocket();}
 Network_DetachSocketFromCurrentThread();*(short*)(state+0x70)&=~6;
 System_SendMessageWithOverlayFallback((*(signed char*)(state+0x73)==2?*(void**)(state+0x68):*(void**)(state+0x64)),0);
 int irq=_Z20DisableIRQInterruptsv();System_AppendCallbackToGlobalList(state);Network_RegisterClosedSocket(state);_Z20SetIRQInterruptStatei(irq);*(short*)(state+0x70)|=32;return 0;
}
