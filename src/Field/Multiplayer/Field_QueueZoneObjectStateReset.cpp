#include <globaldefs.h>
ARM
struct Object;
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(Object*,const void*,short);
struct QueuedTripleRecord {unsigned char type;char pad[3];short first,third,second;char unknown[10];};
// Original: arm9/ov017 @ 0x021CFE40; symbol: func_ov017_021cfe40; size: 0x44.
// Queues type A6 with the three argument halfwords in observed first/third/second order.
extern "C" void Field_QueueZoneObjectStateReset(short first,short second,short third){
 QueuedTripleRecord record;
 Object* object=(Object*)Network_GetCommandRecordPool();
 short* triple=&record.first;
 record.type=0xa6;triple[0]=first;triple[2]=second;triple[1]=third;
 Network_QueueOutgoingRecord(object,&record,0);
}
