#include <globaldefs.h>
ARM
#include <std_library_functions.h>
struct Object;
extern "C" void* ReadGlobalAt02100044();
extern "C" void MoveQueuedRecordAndApplySourceValue(Object*,const void*,short);
struct Payload { unsigned char id,offset; unsigned char count:7; unsigned char last:1; unsigned char bytes[13]; };
struct Packet { unsigned char type,pad[3]; Payload payload; };
// Original: arm9/ov017 @ 0x021D0EF8; symbol: func_ov017_021d0ef8; size: 0x9C.
extern "C" void Network_QueueTwelveByteDataChunk(int id,const unsigned char* source,int total,int offset,int* sent) {
 Object* object=(Object*)ReadGlobalAt02100044();
 Packet packet;
 Payload* payload=&packet.payload;
 payload->id=id;
 packet.type=0xab;
 *sent=total-offset;
 if(*sent>12) *sent=12;
 else payload->last=1;
 payload->count=(unsigned char)*sent;
 payload->offset=offset;
 memcpy(payload->bytes,source+offset,*sent);
 MoveQueuedRecordAndApplySourceValue(object,&packet,0);
}
