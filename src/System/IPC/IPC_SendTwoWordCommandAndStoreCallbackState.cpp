#include <globaldefs.h>
#include <Resource/Script.h>
ARM
// Original data: arm9/main @ 0x21117ec; symbol: data_021117ec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int _Z20DisableIRQInterruptsv();extern "C" int _Z20SetIRQInterruptStatei(int);extern "C" int System_ClaimGlobalInitializationFlag();extern "C" void RetryArm7CommandEightUntilSent(unsigned);extern "C" unsigned PMGoSleepMode_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020CE4E8; symbol: func_020ce4e8; size: 0x84.
extern "C" int IPC_SendTwoWordCommandAndStoreCallbackState(unsigned command,unsigned value,unsigned a,unsigned b,unsigned c){int irq=_Z20DisableIRQInterruptsv();if(!System_ClaimGlobalInitializationFlag()){_Z20SetIRQInterruptStatei(irq);return 1;}PMGoSleepMode_UnknownRoleZeroInitializedStorage[8]=b;PMGoSleepMode_UnknownRoleZeroInitializedStorage[9]=c;PMGoSleepMode_UnknownRoleZeroInitializedStorage[10]=a;RetryArm7CommandEightUntilSent((command&255)|0x02006100);RetryArm7CommandEightUntilSent(0x01010000|(unsigned short)value);_Z20SetIRQInterruptStatei(irq);return 0;}
