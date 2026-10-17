#include <globaldefs.h>
ARM
#include <System/IPC.h>
struct IPCState {unsigned short initialized,pad;unsigned a;char pad8[8];unsigned short b,pad12;unsigned c;char pad18[28];unsigned short d,e,f,g;}; extern "C" IPCState data_021117b0;extern "C" void IPC_HandleReplyChannelAndErrorCallback(unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020CD890; symbol: func_020cd890; size: 0x78.
extern "C" void TouchInput_InitializeIPCHandler(){if(data_021117b0.initialized)return;data_021117b0.initialized=1;InitializeInterProcessorCommunication();data_021117b0.b=0;data_021117b0.a=0;data_021117b0.c=0;data_021117b0.e=0;data_021117b0.d=0;data_021117b0.g=0;data_021117b0.f=0;while(!IsIPCCommandHandlerRegistered(6,IPCSide_Arm7)){}SetArm9IPCCommandHandler(6,IPC_HandleReplyChannelAndErrorCallback);}
