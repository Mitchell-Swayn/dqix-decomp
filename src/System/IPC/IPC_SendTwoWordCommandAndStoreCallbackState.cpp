#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" int _Z20DisableIRQInterruptsv();extern "C" int _Z20SetIRQInterruptStatei(int);extern "C" int System_ClaimGlobalInitializationFlag();extern "C" void RetryArm7CommandEightUntilSent(unsigned);extern "C" unsigned data_021117ec[];
// Original: arm9/main @ 0x020CE4E8; symbol: func_020ce4e8; size: 0x84.
extern "C" int IPC_SendTwoWordCommandAndStoreCallbackState(unsigned command,unsigned value,unsigned a,unsigned b,unsigned c){int irq=_Z20DisableIRQInterruptsv();if(!System_ClaimGlobalInitializationFlag()){_Z20SetIRQInterruptStatei(irq);return 1;}data_021117ec[8]=b;data_021117ec[9]=c;data_021117ec[10]=a;RetryArm7CommandEightUntilSent((command&255)|0x02006100);RetryArm7CommandEightUntilSent(0x01010000|(unsigned short)value);_Z20SetIRQInterruptStatei(irq);return 0;}
