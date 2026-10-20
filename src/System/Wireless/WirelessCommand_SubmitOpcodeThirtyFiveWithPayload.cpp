#include <globaldefs.h>
ARM
#pragma optimize_for_size off
#pragma optimization_level 3
extern "C" void WMi_GetSystemWork();extern "C" int WirelessCommand_ReadInitializedStatus();extern "C" void WMi_SetCallbackTable(unsigned,unsigned);extern "C" void MIi_CpuClear32(unsigned,void*,unsigned);extern "C" void MIi_CpuCopy32(const void*,void*,unsigned);extern "C" int WMi_SendCommandDirect(void*,unsigned);struct Command{unsigned short type,pad;char payload[28];};
// Original: arm9/main @ 0x020D5900; symbol: func_020d5900; size: 0x74.
extern "C" int WirelessCommand_SubmitOpcodeThirtyFiveWithPayload(unsigned a,const void* data){Command cmd;WMi_GetSystemWork();int result=WirelessCommand_ReadInitializedStatus();if(result==0){WMi_SetCallbackTable(35,a);MIi_CpuClear32(0,&cmd,32);cmd.type=35;MIi_CpuCopy32(data,cmd.payload,28);result=WMi_SendCommandDirect(&cmd,32);if(!result)result=2;}return result;}
