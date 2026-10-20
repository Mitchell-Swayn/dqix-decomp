#include <globaldefs.h>
#include <System/IPC.h>
struct State {unsigned short initialized,pad;unsigned first,second;char padc[16];unsigned a,b;};
// Original data: arm9/main @ 0x21117ec; symbol: data_021117ec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" State PMGoSleepMode_UnknownRoleZeroInitializedStorage;
extern "C" void IPC_HandleCommand60Response(unsigned,unsigned,unsigned);
extern "C" void WaitByLoop(unsigned);
// Original: arm9/main @ 0x020CE270; symbol: func_020ce270; size: 0x98.
extern "C" void PowerManagement_InitializeIPCHandler() {if(PMGoSleepMode_UnknownRoleZeroInitializedStorage.initialized)return;PMGoSleepMode_UnknownRoleZeroInitializedStorage.initialized=1;PMGoSleepMode_UnknownRoleZeroInitializedStorage.a=0;PMGoSleepMode_UnknownRoleZeroInitializedStorage.b=0;InitializeInterProcessorCommunication();if(!IsIPCCommandHandlerRegistered(8,IPCSide_Arm7))do{WaitByLoop(100);}while(!IsIPCCommandHandlerRegistered(8,IPCSide_Arm7));SetArm9IPCCommandHandler(8,IPC_HandleCommand60Response);unsigned value=*(volatile unsigned*)0x027ffc3c;PMGoSleepMode_UnknownRoleZeroInitializedStorage.second=value;PMGoSleepMode_UnknownRoleZeroInitializedStorage.first=value;}
