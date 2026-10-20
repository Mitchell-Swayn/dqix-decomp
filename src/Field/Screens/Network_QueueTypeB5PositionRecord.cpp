#include <globaldefs.h>
ARM
extern "C" { void* Network_GetConnectionManager(); void* Network_GetCommandRecordPool(); int Network_IsSessionActive(void*); int Network_GetLocalMemberId(char*); void Network_QueueOutgoingRecord(void*,const void*,short); }
struct Record { unsigned char type,pad[3]; short id,field6,field8,fieldA,x,y,z; };
// Original: arm9/ov017 @ 0x021D1DC0; symbol: func_ov017_021d1dc0; size: 0x90.
extern "C" void Network_QueueTypeB5PositionRecord(int id,int field6,int* position,int field8,int fieldA) {
 if(Network_IsSessionActive(Network_GetConnectionManager()) && !Network_GetLocalMemberId((char*)Network_GetConnectionManager())) {
  void* queue=Network_GetCommandRecordPool();
  Record record;
  record.type=0xb5;
  record.id=id;
  record.field6=field6;
  record.field8=field8;
  record.fieldA=fieldA;
  record.x=position[0]>>7;
  record.y=position[1]>>7;
  record.z=position[2]>>7;
  Network_QueueOutgoingRecord(queue,&record,0);
 }
}
