#include <globaldefs.h>
extern "C" void _Z37InitializeInterProcessorCommunicationv(); extern "C" int _Z29IsIPCCommandHandlerRegisteredi7IPCSide(int,int); extern "C" void _Z24SetArm9IPCCommandHandleriPFvjjjE(int,void(*)(unsigned,unsigned,unsigned)); extern "C" void System_HandleRtcFifoResponse(unsigned,unsigned,unsigned);
// Original data: arm9/main @ 0x2111818; symbol: data_02111818.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct IPCState { unsigned short initialized,pad; unsigned reserved[2]; unsigned a,b,c,d; unsigned tail[3]; unsigned e; }; extern "C" IPCState RTCGetDate_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x020CF020; symbol: func_020cf020; size: 0x6C.
extern "C" ARM void RealTimeClock_InitializeIPCHandler() { if(RTCGetDate_UnknownRoleZeroInitializedStorage.initialized) return; RTCGetDate_UnknownRoleZeroInitializedStorage.initialized=1; RTCGetDate_UnknownRoleZeroInitializedStorage.a=0; RTCGetDate_UnknownRoleZeroInitializedStorage.b=0; RTCGetDate_UnknownRoleZeroInitializedStorage.e=0; RTCGetDate_UnknownRoleZeroInitializedStorage.c=0; RTCGetDate_UnknownRoleZeroInitializedStorage.d=0; _Z37InitializeInterProcessorCommunicationv(); while(!_Z29IsIPCCommandHandlerRegisteredi7IPCSide(5,1)) {} _Z24SetArm9IPCCommandHandleriPFvjjjE(5,System_HandleRtcFifoResponse); }
