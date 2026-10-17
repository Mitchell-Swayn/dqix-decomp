#include <globaldefs.h>
ARM
struct Object;
extern "C" void* ReadGlobalAt02100044();
extern "C" void* Object_GetGlobalConnectionState();
extern "C" bool TestInactiveOrPrimaryIndexState(unsigned*);
extern "C" void MoveQueuedRecordAndApplySourceValue(Object*,const void*,short);
extern "C" void QueueDayTimerMessage93();
// Original: arm9/ov017 @ 0x021C5284; symbol: func_ov017_021c5284; size: 0x88.
extern "C" void Network_QueueRecord61(const unsigned char* p) {
Object* obj=(Object*)ReadGlobalAt02100044();
unsigned char message[20];
message[0]=0x3d;
*(unsigned short*)(message+4)=*(const unsigned short*)p;
*(unsigned short*)(message+6)=*(const unsigned short*)(p+2);
message[8]=p[4]; message[9]=p[5];
*(unsigned short*)(message+10)=*(const unsigned short*)(p+6);
message[12]=p[8]; message[13]=p[9];
*(unsigned short*)(message+14)=*(const unsigned short*)(p+10);
message[16]=p[12];
MoveQueuedRecordAndApplySourceValue(obj,message,0);
if(TestInactiveOrPrimaryIndexState((unsigned*)Object_GetGlobalConnectionState())) QueueDayTimerMessage93();
}
