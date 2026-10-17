#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" {
void MIi_CpuCopy16(const void*,volatile void*,int);
int TestCurrentStatusAgainstVariadicAllowedValues(unsigned,...);
unsigned ReadOptionalSharedHalfwordStatusUnderIRQGuard();
unsigned WirelessCommand_ReadSharedWord14CLowHalfwordAtomically();
int ValidateStatusNineOrTenAndReadSharedActiveFlags(int,int,void*,unsigned,unsigned short,unsigned short,unsigned short);
void CopySelectedEnabledBitBlockToDestination(unsigned char*,unsigned,unsigned);
void WirelessPacketQueue_AdvanceAndSubmitEmptyCurrentPacket(unsigned char*,int);
void HandleMatchedCallbackObjectAndEventStatus();
}
#define H(p,o) (*(unsigned short*)((p)+(o)))
// Original: arm9/main @ 0x020D5FD0; symbol: func_020d5fd0; size: 0x348.
extern "C" int Network_ExchangeQueuedWirelessPacket(unsigned char* p,void* send,void* receive){
int result=TestCurrentStatusAgainstVariadicAllowedValues(2,9,10);if(result)return result;
if(!p)return 6;if(!send)return 6;if(!receive)return 6;
unsigned mode=ReadOptionalSharedHalfwordStatusUnderIRQGuard();unsigned flags;if(!mode)flags=WirelessCommand_ReadSharedWord14CLowHalfwordAtomically();
unsigned state=H(p,0x81c);if(state==5)return 1;if(state!=1&&state!=4)return 3;
int copied;unsigned slot;unsigned char* packet;int status=5;int empty;
if(!mode){copied=0;empty=0;
 if(state==4){H(p,0x81c)=1;slot=(H(p,0x808)+3)&3;
 int ret=ValidateStatusNineOrTenAndReadSharedActiveFlags((int)HandleMatchedCallbackObjectAndEventStatus,(int)p,p+(slot<<9),H(p,0x814),H(p,0x80e)&flags,H(p,0x816),1);
 if(ret==7){H(p+(slot<<1),0x800)=0xffff;H(p,0x80a)=(H(p,0x80a)+1)&3;}
 else if(ret!=0&&ret!=2){H(p,0x81c)=status;return 1;}
 }
 if(H(p,0x80c)!=H(p,0x80a)){
 unsigned offset=H(p,0x80c)<<9;H(p,offset)|=1;
 MIi_CpuCopy16(p+(H(p,0x80c)<<9),receive,0x200);
 H(p,0x81a)=H(p+(H(p,0x80c)<<1),0x800);H(p,0x80c)=(H(p,0x80c)+1)&3;copied=1;status=0;
 if(!H(p,0x818)&&flags&&H(p,H(p,0x808)<<9)==1)empty=1;else empty=0;
 }
 WirelessPacketQueue_AdvanceAndSubmitEmptyCurrentPacket(p,0);
 if(copied){CopySelectedEnabledBitBlockToDestination(p,0,(unsigned)send);if(!H(p,0x818))WirelessPacketQueue_AdvanceAndSubmitEmptyCurrentPacket(p,empty);}
}else{int copied2=0;
 if(state==4){copied2=1;H(p,0x81c)=copied2;}
 else if(H(p,0x80c)!=H(p,0x808)){
 unsigned offset=H(p,0x80c)<<9;
 if(!(H(p,offset)&1))H(p,offset)|=1;
 else{MIi_CpuCopy16(p+offset,receive,0x200);copied2=1;status=0;H(p,0x81a)=H(p+(H(p,0x80c)<<1),0x800);H(p,0x80c)=(H(p,0x80c)+1)&3;}
 }
 if(copied2){packet=p+(H(p,0x80a)<<9);MIi_CpuCopy16(send,packet+0x20,H(p,0x810));
 int ret=ValidateStatusNineOrTenAndReadSharedActiveFlags((int)HandleMatchedCallbackObjectAndEventStatus,(int)p,packet+0x20,H(p,0x810),H(p,0x80e),H(p,0x816),1);
 H(p,0x80a)=(H(p,0x80a)+1)&3;
 if(ret!=2&&ret!=0){H(p,0x81c)=5;status=1;}
 }
}
return status;
}
