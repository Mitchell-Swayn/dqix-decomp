#include <globaldefs.h>
ARM
#pragma always_inline on
inline unsigned short SwapHalfword(int value){return(value>>8)|(value<<8);}
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
extern "C" {unsigned char* Network_FindTcpSocketForReceivedSegment(void*);void Network_SendTcpResetForReceivedSegment(void*,void*,int,int);void _Z28CycleCurrentPriorityContextsv();void Network_ParseTcpMaximumSegmentSize(unsigned char*,unsigned char*);void Network_SendTcpAcknowledgment(void*,unsigned);void _Z25MarkContextReadyAndSwitchP16ProcessorContext(void*);}
// Original: arm9/ov031 @ 0x02202334; symbol: Network_AcceptTcpSetupAndResumeWaitingContext; size: 0xf8.
// Accepts setup packet, stores byte-swapped sequence/window values and resumes waiting processor context.
extern "C" void Network_CompleteActiveTcpHandshake(void* self,unsigned char* packet,int size){unsigned char* connection=Network_FindTcpSocketForReceivedSegment(self);if(!connection||connection[8]!=2){Network_SendTcpResetForReceivedSegment(self,packet,size,0);return;}_Z28CycleCurrentPriorityContextsv();int low=U(packet,6);int high=U(packet,4);W(connection,0x24)=(((unsigned)SwapHalfword(high)<<16)|SwapHalfword(low))+1;low=U(packet,10);high=U(packet,8);W(connection,0x30)=((unsigned)SwapHalfword(high)<<16)|SwapHalfword(low);U(connection,0x2c)=SwapHalfword(U(packet,14));Network_ParseTcpMaximumSegmentSize(packet,connection);Network_SendTcpAcknowledgment(connection,0);connection[8]=4;if(W(connection,4)==1){W(connection,4)=0;_Z25MarkContextReadyAndSwitchP16ProcessorContext(P(connection,0));}}
