#include <globaldefs.h>
extern "C" void _Z37InitializeInterProcessorCommunicationv(); extern "C" int _Z29IsIPCCommandHandlerRegisteredi7IPCSide(int,int); extern "C" void _Z24SetArm9IPCCommandHandleriPFvjjjE(int,void(*)(unsigned,unsigned,unsigned)); extern "C" void System_HandleRtcFifoResponse(unsigned,unsigned,unsigned);
struct IPCState { unsigned short initialized,pad; unsigned reserved[2]; unsigned a,b,c,d; unsigned tail[3]; unsigned e; }; extern "C" IPCState data_02111818;
// Original: arm9/main @ 0x020CF020; symbol: func_020cf020; size: 0x6C.
extern "C" ARM void RealTimeClock_InitializeIPCHandler() { if(data_02111818.initialized) return; data_02111818.initialized=1; data_02111818.a=0; data_02111818.b=0; data_02111818.e=0; data_02111818.c=0; data_02111818.d=0; _Z37InitializeInterProcessorCommunicationv(); while(!_Z29IsIPCCommandHandlerRegisteredi7IPCSide(5,1)) {} _Z24SetArm9IPCCommandHandleriPFvjjjE(5,System_HandleRtcFifoResponse); }
