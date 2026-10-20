#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e53c; symbol: data_ov031_0224e53c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char *NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage;
extern "C" int WirelessCommand_SubmitOpcodeOne(void *);
extern "C" void Network_HandleWirelessResetResult();
extern "C" void Network_SetWirelessStateAndConnectionAlarm(int);
extern "C" void Network_ConsumeSharedValueAndDispatch(int,int,int,unsigned);
// Original: arm9/ov031 @ 0x0220DB6C; symbol: StartSharedWirelessTransition; size: 0x5C.
// Guards the shared wireless state byte, submits opcode one, and dispatches the fallback state when submission does not return two.
extern "C" void StartSharedWirelessTransition(void) {
    char *state=NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage; if(*(unsigned char *)(state+0x226b)!=0) return; *(unsigned char *)(state+0x226b)=1; int status=WirelessCommand_SubmitOpcodeOne((void *)Network_HandleWirelessResetResult); if(status==2) return; Network_SetWirelessStateAndConnectionAlarm(11); Network_ConsumeSharedValueAndDispatch(7,0,0,0x610);
}
