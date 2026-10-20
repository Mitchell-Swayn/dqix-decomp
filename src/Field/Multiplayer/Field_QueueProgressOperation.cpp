#include <globaldefs.h>
ARM
struct Object;
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(Object*,const void*,short);
struct PackedId { unsigned char id:7, flag:1; };
struct Record8D { unsigned char type; unsigned char pad[3]; PackedId packed; unsigned char pad5; unsigned short first,second; unsigned char tail[10]; };
// Original: arm9/ov017 @ 0x021CE110; symbol: func_ov017_021ce110; size: 0x64.
// Queues type 0x8D, packing the low seven ID bits and low flag bit with two halfwords.
// Other packet bytes retain the original unspecified stack contents.
extern "C" void Field_QueueProgressOperation(unsigned char id,unsigned short first,unsigned short second,unsigned char flag) {
    Object* queue=(Object*)Network_GetCommandRecordPool();
    Record8D record;
    record.type=0x8d;
    record.first=first;
    record.second=second;
    record.packed.id=id;
    record.packed.flag=flag;
    Network_QueueOutgoingRecord(queue,&record,0);
}
