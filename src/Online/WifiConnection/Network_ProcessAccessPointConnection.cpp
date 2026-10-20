#include <globaldefs.h>
ARM
#define D(p) ((unsigned)(p))
#define U32(p) (*(unsigned*)(p))
#define U16(p) (*(unsigned short*)(p))
#define S16(p) (*(short*)(p))
#define U8(p) (*(unsigned char*)(p))
#define S8(p) (*(signed char*)(p))
#define V32(p) (*(volatile unsigned*)(p))
#define V16(p) (*(volatile unsigned short*)(p))
extern "C" unsigned GameState_InvokeMaskHandlersEightAndSixteen(...);
extern "C" unsigned System_SelectState11Or12FromPriorityRecord(...);
extern "C" unsigned Network_GetConnectionPhase(...);
extern "C" unsigned Network_InitializePriorityScanWhenWirelessReady(...);
extern "C" unsigned Util_TestSelectedStringAgainstEligibleRecords(...);
extern "C" unsigned System_SelectStateHandlerByOptionalByte(...);
extern "C" unsigned Network_ProcessAccessPointSearchPhase(...);
extern "C" unsigned _Z20DisableIRQInterruptsv(...);
extern "C" unsigned _Z20SetIRQInterruptStatei(...);
extern "C" unsigned Network_UpdateConnectionProgress(...);
extern "C" unsigned Network_ProcessConnectionRecovery(...);
extern "C" unsigned WfcConnection_AdvanceAddressAndInternetCheck(...);
// Original: arm9/ov031 @ 0x02212ee8; symbol: System_AdvanceOptionalStateAndReturnCompletion; size: 0xd0.
extern "C" int Network_ProcessAccessPointConnection(){
unsigned state=Network_GetConnectionPhase();
if(state==1)state=Network_InitializePriorityScanWhenWirelessReady();else if(state<7){unsigned irq=_Z20DisableIRQInterruptsv();state=Network_ProcessAccessPointSearchPhase();Network_UpdateConnectionProgress(state);_Z20SetIRQInterruptStatei(irq);}else if(state<9)state=System_SelectStateHandlerByOptionalByte();else if(state<10)state=Network_ProcessConnectionRecovery();else if(state<16)state=WfcConnection_AdvanceAddressAndInternetCheck();else if(state==17)state=System_SelectState11Or12FromPriorityRecord();
Network_UpdateConnectionProgress(state);if(state==16){int result=Util_TestSelectedStringAgainstEligibleRecords();GameState_InvokeMaskHandlersEightAndSixteen();return result;}if(state!=18)return 0;GameState_InvokeMaskHandlersEightAndSixteen();return -1;
}