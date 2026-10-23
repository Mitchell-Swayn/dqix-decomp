#include <globaldefs.h>
ARM
extern "C" int _Z25MarkContextReadyAndSwitchP16ProcessorContext(...);
extern "C" unsigned char* Network_FindTcpSocketForReceivedSegment(void*,void*);
extern "C" int Network_SendTcpAcknowledgment(...);
extern "C" int Network_SendTcpFinishAcknowledgment(...);
extern "C" int Network_SendTcpResetForReceivedSegment(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov031 @ 0x02202744; symbol: AdvanceContextStateOrDispatchFallback.
extern "C" void Network_ProcessTcpFinishSegment(void* self,void* arg1,int arg2){
char* context=C(Network_FindTcpSocketForReceivedSegment(self,arg1));if(!context)return;switch(B(context,8)){case 7:W(context,36)++;Network_SendTcpAcknowledgment(context,0);B(context,8)=9;return;case 8:W(context,36)++;Network_SendTcpAcknowledgment(context,0);B(context,8)=0;if(W(context,4)==2){W(context,4)=0;_Z25MarkContextReadyAndSwitchP16ProcessorContext(P(context,0));}return;case 4:W(context,36)++;Network_SendTcpFinishAcknowledgment(context,0);B(context,8)=6;return;default:Network_SendTcpResetForReceivedSegment(self,arg1,arg2,0);return;}
}
