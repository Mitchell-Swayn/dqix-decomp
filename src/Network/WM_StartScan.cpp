#include <globaldefs.h>
ARM
#pragma optimize_for_size off
struct Input{int value;unsigned short slot,word;unsigned char bytes[6];};struct Packet{unsigned short opcode,slot;int value;unsigned short word;unsigned char bytes[6];};extern "C" {int TestCurrentStatusAgainstVariadicAllowedValues(int,int,int,int);void WMi_SetCallbackTable(int,int);int WMi_SendCommandDirect(Packet*,int);
// Original: arm9/main @ 0x020D5254; symbol: func_020d5254; size: 0xEC.
int WM_StartScan(int value,Input* in){int result=TestCurrentStatusAgainstVariadicAllowedValues(3,2,3,5);if(result)return result;if(!in)return 6;if(!in->value)return 6;if(in->slot<1||in->slot>14)return 6;WMi_SetCallbackTable(10,value);Packet packet;packet.opcode=10;packet.slot=in->slot;packet.value=in->value;packet.word=in->word;packet.bytes[0]=in->bytes[0];packet.bytes[1]=in->bytes[1];packet.bytes[2]=in->bytes[2];packet.bytes[3]=in->bytes[3];packet.bytes[4]=in->bytes[4];packet.bytes[5]=in->bytes[5];result=WMi_SendCommandDirect(&packet,16);if(!result)result=2;return result;}}
