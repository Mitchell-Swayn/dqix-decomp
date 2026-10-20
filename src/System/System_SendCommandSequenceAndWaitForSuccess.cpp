#include <globaldefs.h>
ARM
extern "C" int _Z20DisableIRQInterruptsv();
extern "C" int _Z20SetIRQInterruptStatei(int);
extern "C" int System_ClaimGlobalInitializationFlag();
extern "C" void RetryArm7CommandEightUntilSent(int);
extern "C" void OS_SpinWait(unsigned);
extern "C" void PowerManagement_StoreCommandResultCallback(unsigned,unsigned*);
struct IPCState {char pad[32];void (*callback)(unsigned,unsigned*);volatile int* output;};
// Original data: arm9/main @ 0x21117ec; symbol: data_021117ec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" IPCState PMGoSleepMode_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x020CE39C; symbol: func_020ce39c; size: 0xC0.
extern "C" void System_SendCommandSequenceAndWaitForSuccess(const int* commands,int count) {
volatile int result;
for(;;) {
int i;
int irq=_Z20DisableIRQInterruptsv();
if(!System_ClaimGlobalInitializationFlag()) {_Z20SetIRQInterruptStatei(irq);continue;}
result=-0x10000;
PMGoSleepMode_UnknownRoleZeroInitializedStorage.callback=PowerManagement_StoreCommandResultCallback;
PMGoSleepMode_UnknownRoleZeroInitializedStorage.output=&result;
for(i=0;i<count;++i) RetryArm7CommandEightUntilSent(commands[i]);
_Z20SetIRQInterruptStatei(irq);
while(result==-0x10000) OS_SpinWait(0xa3a47);
if(!result) return;
OS_SpinWait(0xa3a47);
}
}
