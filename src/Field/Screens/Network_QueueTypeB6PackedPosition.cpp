#include <globaldefs.h>
ARM
struct Position { short x,y,z; };
struct Payload { unsigned char kind,subtype; unsigned short index; Position position; };
struct Record { unsigned char type,pad[3]; Payload payload; unsigned padEnd; };
extern "C" { void* Network_GetCommandRecordPool(); void* _ZN9GameState11GetInstanceEv(); char* _ZN9GameState27GetMaybeFieldMonsterByIndexEi(void*,int); void _Z16Vector3fix16CopyP8Vector3sPKS_(Position*,const Position*); void Network_QueueOutgoingRecord(void*,const void*,short); }
// Original: arm9/ov017 @ 0x021D360C; symbol: func_ov017_021d360c; size: 0xA8.
extern "C" void Network_QueueTypeB6PackedPosition(int kind,unsigned subtype,unsigned short index,Position position) {
 void* queue=Network_GetCommandRecordPool();
 Record record;
 Payload* payload=&record.payload;
 if(kind==1) {
  int small=index<=3;
  if(!small) {
   char* monster=_ZN9GameState27GetMaybeFieldMonsterByIndexEi(_ZN9GameState11GetInstanceEv(),index);
   if(!monster) return;
   index=*(unsigned short*)(monster+0x16a)+4;
  }
 }
 record.type=0xb6;
 payload->kind=kind;
 payload->subtype=subtype;
 payload->index=index;
 _Z16Vector3fix16CopyP8Vector3sPKS_(&payload->position,&position);
 Network_QueueOutgoingRecord(queue,&record,0);
}
