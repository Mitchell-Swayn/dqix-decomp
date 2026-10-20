#include <globaldefs.h>
ARM
struct Object;
extern "C" void* Network_GetCommandRecordPool();
extern "C" void* Network_GetConnectionManager();
extern "C" bool Network_IsParentOrOffline(unsigned*);
extern "C" void Network_QueueOutgoingRecord(Object*,const void*,short);
extern "C" void Field_QueueDayTimerSynchronization();
// Original: arm9/ov017 @ 0x021C5284; symbol: func_ov017_021c5284; size: 0x88.
extern "C" void Network_QueueEncounterRequest(const unsigned char* p) {
Object* obj=(Object*)Network_GetCommandRecordPool();
unsigned char message[20];
message[0]=0x3d;
*(unsigned short*)(message+4)=*(const unsigned short*)p;
*(unsigned short*)(message+6)=*(const unsigned short*)(p+2);
message[8]=p[4]; message[9]=p[5];
*(unsigned short*)(message+10)=*(const unsigned short*)(p+6);
message[12]=p[8]; message[13]=p[9];
*(unsigned short*)(message+14)=*(const unsigned short*)(p+10);
message[16]=p[12];
Network_QueueOutgoingRecord(obj,message,0);
if(Network_IsParentOrOffline((unsigned*)Network_GetConnectionManager())) Field_QueueDayTimerSynchronization();
}
