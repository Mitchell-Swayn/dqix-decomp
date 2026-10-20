#include <globaldefs.h>
ARM
struct Vec { int x,y,z; };
struct Payload { short id,x,y,z,value; float timer; };
struct Message { unsigned char tag; Payload payload; };
extern "C" {void* _ZN9GameState11GetInstanceEv();float _ZNK9GameState11GetDayTimerEv(void*);void* Network_GetCommandRecordPool();void Network_QueueOutgoingRecord(void*,const void*,short);}
// Original: arm9/ov017 @ 0x021C4664; symbol: func_ov017_021c4664; size: 0x88.
extern "C" void QueuePositionAndDayTimerMessage36(int id,Vec pos,short value){
void* game=_ZN9GameState11GetInstanceEv();
void* queue=Network_GetCommandRecordPool();
Message message;
Payload* payload=&message.payload;
message.tag=0x36;
payload->id=id;
payload->x=pos.x>>10;
payload->y=pos.y>>10;
payload->z=pos.z>>10;
payload->value=value;
payload->timer=_ZNK9GameState11GetDayTimerEv(game);
Network_QueueOutgoingRecord(queue,&message,0);
}
