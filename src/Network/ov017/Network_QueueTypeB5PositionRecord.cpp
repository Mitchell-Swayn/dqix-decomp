#include <globaldefs.h>
ARM
extern "C" { void* Object_GetGlobalConnectionState(); void* ReadGlobalAt02100044(); int IsFirstWordNonzero(void*); int ReadIndexedSignedField1038(char*); void MoveQueuedRecordAndApplySourceValue(void*,const void*,short); }
struct Record { unsigned char type,pad[3]; short id,field6,field8,fieldA,x,y,z; };
// Original: arm9/ov017 @ 0x021D1DC0; symbol: func_ov017_021d1dc0; size: 0x90.
extern "C" void Network_QueueTypeB5PositionRecord(int id,int field6,int* position,int field8,int fieldA) {
 if(IsFirstWordNonzero(Object_GetGlobalConnectionState()) && !ReadIndexedSignedField1038((char*)Object_GetGlobalConnectionState())) {
  void* queue=ReadGlobalAt02100044();
  Record record;
  record.type=0xb5;
  record.id=id;
  record.field6=field6;
  record.field8=field8;
  record.fieldA=fieldA;
  record.x=position[0]>>7;
  record.y=position[1]>>7;
  record.z=position[2]>>7;
  MoveQueuedRecordAndApplySourceValue(queue,&record,0);
 }
}
