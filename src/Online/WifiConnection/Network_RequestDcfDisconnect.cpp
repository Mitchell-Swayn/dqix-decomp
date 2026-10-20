#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
// Original data: arm9/ov031 @ 0x224e53c; symbol: data_ov031_0224e53c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" {int _Z20DisableIRQInterruptsv();int _Z20SetIRQInterruptStatei(int);void Network_SetWirelessStateAndConnectionAlarm(int);int WirelessCommand_SubmitOpcodeNineteenIfSharedWord10Set(void*);void Network_HandleEndDcfResult(void*);extern unsigned char* NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage;}
// Original: arm9/ov031 @0x0220d214; symbol:Network_RequestStateNineTransitionWithIRQGuard; size:0x11c.
// Requests state-nine wireless transition under IRQ guard and maps shared state and command outcomes to status codes.
extern "C" int Network_RequestDcfDisconnect(){int irq=_Z20DisableIRQInterruptsv();if(!NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage){_Z20SetIRQInterruptStatei(irq);return 1;}switch(W(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage,0x2260)){case 10:_Z20SetIRQInterruptStatei(irq);return 2;case 3:_Z20SetIRQInterruptStatei(irq);return 0;default:_Z20SetIRQInterruptStatei(irq);return 1;case 9:break;}if(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage[0x226b]==1){Network_SetWirelessStateAndConnectionAlarm(10);H(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage,0x2280)=6;}else{switch(WirelessCommand_SubmitOpcodeNineteenIfSharedWord10Set((void*)Network_HandleEndDcfResult)){case 2:Network_SetWirelessStateAndConnectionAlarm(10);H(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage,0x2280)=6;break;case 8:_Z20SetIRQInterruptStatei(irq);return 4;case 3:default:Network_SetWirelessStateAndConnectionAlarm(11);_Z20SetIRQInterruptStatei(irq);return 7;}}_Z20SetIRQInterruptStatei(irq);return 3;}
