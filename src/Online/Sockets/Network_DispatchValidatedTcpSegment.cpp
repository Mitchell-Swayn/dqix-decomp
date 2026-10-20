#include <globaldefs.h>
ARM
extern "C" int Network_ProcessTcpFinishSegment(...);
extern "C" int CyclePriorityContextAndReleaseExpiredWrapper(...);
extern "C" int Network_CompleteActiveTcpHandshake(...);
extern "C" int System_CheckCombinedFieldValue(...);
extern "C" int Network_HandleTcpSynchronizeSegment(...);
extern "C" int Network_SendTcpResetForReceivedSegment(...);
extern "C" int Network_ProcessTcpAcknowledgmentAndPayload(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov031 @ 0x0220284C; symbol: DispatchTcpPacketByControlFlagsAndPayloadLength.
extern "C" void Network_DispatchValidatedTcpSegment(char*self,char*packet,int size){
if(System_CheckCombinedFieldValue(packet,size,self,6))return;int header=B(packet,12)&240;int flags=B(packet,13);size-=header/4;switch(flags&23){case 2:if(flags&40)return;Network_HandleTcpSynchronizeSegment(self,packet,size);break;case 18:if(flags&40)return;Network_CompleteActiveTcpHandshake(self,packet,size);break;case 16:case 17:Network_ProcessTcpAcknowledgmentAndPayload(self,packet,size);break;case 1:Network_ProcessTcpFinishSegment(self,packet,size);break;default:if(flags&4)CyclePriorityContextAndReleaseExpiredWrapper(self,packet);else Network_SendTcpResetForReceivedSegment(self,packet,size,0);break;}
}
