#include <globaldefs.h>
#include <System/Memory.h>
ARM
extern "C" {extern char data_ov031_0224ce68[];extern volatile unsigned data_ov031_0224c980[];void func_ov031_02200850(void*,int,int,int);}
inline unsigned short Swap16(unsigned short value){return (value>>8)|(value<<8);}
// Original: arm9/ov031 @ 0x022017C4; symbol: func_ov031_022017c4; size: 0xA8.
extern "C" void Network_BuildAndSendArpReply(char* packet){
*(unsigned short*)(packet+6)=0x200;
MI_CpuCopy8(packet+8,packet+0x12,10);
MI_CpuCopy8(data_ov031_0224ce68,packet+8,6);
*(unsigned short*)(packet+14)=Swap16(data_ov031_0224c980[20]>>16);
*(unsigned short*)(packet+16)=Swap16(data_ov031_0224c980[20]);
MI_CpuCopy8(packet+0x12,packet-14,6);
MI_CpuCopy8(data_ov031_0224ce68,packet-8,6);
func_ov031_02200850(packet-14,42,0,0);
}
