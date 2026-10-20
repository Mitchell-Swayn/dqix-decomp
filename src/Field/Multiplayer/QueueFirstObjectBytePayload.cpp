#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
struct Object;
extern "C" unsigned char GameState_ReadFirstObjectIndex(GameState*);
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(Object*,const void*,short);
// Original: arm9/ov017 @ 0x021CC1F8; symbol: func_ov017_021cc1f8; size: 0x74.
// Queues a type-five byte payload only for the first indexed game object.
extern "C" void QueueFirstObjectBytePayload(int index,const char* payload,int count,int value) {
 struct Packet {char type;char unknown[3];char index,count;char payload[4];char value;char tail[9];};
 Packet packet;
 if(index==GameState_ReadFirstObjectIndex(GameState::GetInstance())) {
  Object* queue=(Object*)Network_GetCommandRecordPool();
  packet.type=5;packet.index=index;
  int i=0;
  for(;i<count;i++)packet.payload[i]=payload[i];
  packet.count=count;packet.value=value;
  Network_QueueOutgoingRecord(queue,&packet,0);
 }
}
