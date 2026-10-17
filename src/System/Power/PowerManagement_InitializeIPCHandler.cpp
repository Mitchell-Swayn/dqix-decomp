#include <globaldefs.h>
#include <System/IPC.h>
struct State {unsigned short initialized,pad;unsigned first,second;char padc[16];unsigned a,b;};
extern "C" State data_021117ec;
extern "C" void func_020ce308(unsigned,unsigned,unsigned);
extern "C" void WaitByLoop(unsigned);
// Original: arm9/main @ 0x020CE270; symbol: func_020ce270; size: 0x98.
extern "C" void PowerManagement_InitializeIPCHandler() {if(data_021117ec.initialized)return;data_021117ec.initialized=1;data_021117ec.a=0;data_021117ec.b=0;InitializeInterProcessorCommunication();if(!IsIPCCommandHandlerRegistered(8,IPCSide_Arm7))do{WaitByLoop(100);}while(!IsIPCCommandHandlerRegistered(8,IPCSide_Arm7));SetArm9IPCCommandHandler(8,func_020ce308);unsigned value=*(volatile unsigned*)0x027ffc3c;data_021117ec.second=value;data_021117ec.first=value;}
