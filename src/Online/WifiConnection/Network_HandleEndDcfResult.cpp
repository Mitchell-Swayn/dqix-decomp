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
extern "C" {void Network_SetWirelessStateAndConnectionAlarm(int);void StartSharedWirelessTransition();int ValidateSlotAgainstSharedMaskAndSubmit(int,unsigned);void Network_ConsumeSharedValueAndDispatch(int,int,int,int);void Network_DispatchResultCodeToSharedState();extern unsigned char* NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage;}
// Original: arm9/ov031 @0x0220e694; symbol:Network_HandleOpcodeNineteenTransitionResult; size:0x11c.
// Handles wireless opcode callback result with nested slot-validation and shared-state transition dispatch.
extern "C" void Network_HandleEndDcfResult(unsigned char* result){switch(U(result,2)){case 0:if(W(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage,0x2260)==12){Network_SetWirelessStateAndConnectionAlarm(10);StartSharedWirelessTransition();return;}switch(ValidateSlotAgainstSharedMaskAndSubmit((int)Network_DispatchResultCodeToSharedState,0)){case 2:return;case 8:Network_SetWirelessStateAndConnectionAlarm(12);Network_ConsumeSharedValueAndDispatch(1,(int)NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x2140,0,0x8b4);return;case 3:Network_SetWirelessStateAndConnectionAlarm(10);StartSharedWirelessTransition();return;default:Network_SetWirelessStateAndConnectionAlarm(11);Network_ConsumeSharedValueAndDispatch(7,(int)NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x2140,0,0x8c0);return;}case 1:case 3:Network_SetWirelessStateAndConnectionAlarm(10);StartSharedWirelessTransition();return;case 2:case 4:default:Network_SetWirelessStateAndConnectionAlarm(11);Network_ConsumeSharedValueAndDispatch(7,(int)NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage+0x2140,0,0x8d3);return;}}
