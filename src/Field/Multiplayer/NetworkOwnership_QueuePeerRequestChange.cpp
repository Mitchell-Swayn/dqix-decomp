#include <globaldefs.h>
struct Object;
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(Object*,const void*,short);
struct Command33 {unsigned char code;char alignment[3];struct Payload{unsigned char a,b,unknown,c;char tail[12];} payload;};
// Original: arm9/ov017 @ 0x021CEAE4; symbol: func_ov017_021ceae4; size: 0x44.
// Only code and payload bytes0,1,3 are assigned; other payload bytes are unspecified.
extern "C" ARM void NetworkOwnership_QueuePeerRequestChange(unsigned char a,unsigned char b,unsigned char c){
 Object* queue=(Object*)Network_GetCommandRecordPool();Command33 command;Command33::Payload* payload=&command.payload;
 command.code=0x33;payload->a=a;payload->b=b;payload->c=c;
 Network_QueueOutgoingRecord(queue,&command,0);
}
