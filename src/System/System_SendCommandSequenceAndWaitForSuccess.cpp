#include <globaldefs.h>
ARM
extern "C" int _Z20DisableIRQInterruptsv();
extern "C" int _Z20SetIRQInterruptStatei(int);
extern "C" int System_ClaimGlobalInitializationFlag();
extern "C" void RetryArm7CommandEightUntilSent(int);
extern "C" void OS_SpinWait(unsigned);
extern "C" void WriteOutputWhenNonNull(unsigned,unsigned*);
struct IPCState {char pad[32];void (*callback)(unsigned,unsigned*);volatile int* output;};
extern "C" IPCState data_021117ec;
// Original: arm9/main @ 0x020CE39C; symbol: func_020ce39c; size: 0xC0.
extern "C" void System_SendCommandSequenceAndWaitForSuccess(const int* commands,int count) {
volatile int result;
for(;;) {
int i;
int irq=_Z20DisableIRQInterruptsv();
if(!System_ClaimGlobalInitializationFlag()) {_Z20SetIRQInterruptStatei(irq);continue;}
result=-0x10000;
data_021117ec.callback=WriteOutputWhenNonNull;
data_021117ec.output=&result;
for(i=0;i<count;++i) RetryArm7CommandEightUntilSent(commands[i]);
_Z20SetIRQInterruptStatei(irq);
while(result==-0x10000) OS_SpinWait(0xa3a47);
if(!result) return;
OS_SpinWait(0xa3a47);
}
}
