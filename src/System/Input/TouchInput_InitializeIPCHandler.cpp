#include <globaldefs.h>
ARM
#include <System/IPC.h>
// Original data: arm9/main @ 0x21117b0; symbol: data_021117b0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct IPCState {unsigned short initialized,pad;unsigned a;char pad8[8];unsigned short b,pad12;unsigned c;char pad18[28];unsigned short d,e,f,g;}; extern "C" IPCState TPWaitBusy_UnknownRoleZeroInitializedStorage;extern "C" void IPC_HandleReplyChannelAndErrorCallback(unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020CD890; symbol: func_020cd890; size: 0x78.
extern "C" void TouchInput_InitializeIPCHandler(){if(TPWaitBusy_UnknownRoleZeroInitializedStorage.initialized)return;TPWaitBusy_UnknownRoleZeroInitializedStorage.initialized=1;InitializeInterProcessorCommunication();TPWaitBusy_UnknownRoleZeroInitializedStorage.b=0;TPWaitBusy_UnknownRoleZeroInitializedStorage.a=0;TPWaitBusy_UnknownRoleZeroInitializedStorage.c=0;TPWaitBusy_UnknownRoleZeroInitializedStorage.e=0;TPWaitBusy_UnknownRoleZeroInitializedStorage.d=0;TPWaitBusy_UnknownRoleZeroInitializedStorage.g=0;TPWaitBusy_UnknownRoleZeroInitializedStorage.f=0;while(!IsIPCCommandHandlerRegistered(6,IPCSide_Arm7)){}SetArm9IPCCommandHandler(6,IPC_HandleReplyChannelAndErrorCallback);}
