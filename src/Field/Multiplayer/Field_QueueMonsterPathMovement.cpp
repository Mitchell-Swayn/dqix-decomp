#include <globaldefs.h>
ARM
struct Record { unsigned char type,pad[3]; unsigned short id; unsigned char field6; unsigned char low:4; signed char high:4; unsigned short field8,fieldA; unsigned wordC,word10; };
extern "C" { void* Network_GetCommandRecordPool(); void Network_QueueOutgoingRecord(void*,const void*,short); }
// Original: arm9/ov017 @ 0x021C9168; symbol: func_ov017_021c9168; size: 0x8C.
extern "C" void Field_QueueMonsterPathMovement(int id,int low,int unused,int field8,unsigned wordC,int unused5,unsigned word10,int unused7,int fieldA,int unused9,int high) {
 void* queue=Network_GetCommandRecordPool();
 Record record;
 record.type=0x84;
 record.id=id;
 record.low=(unsigned char)low;
 record.high=(signed char)high;
 record.wordC=wordC;
 record.word10=word10;
 record.fieldA=fieldA;
 record.field8=field8;
 Network_QueueOutgoingRecord(queue,&record,0);
}
