#include <globaldefs.h>
ARM
extern "C" void* GameState_GetObjectWithFlag100(void*,int);
extern "C" unsigned char* GameObject_GetLinkedIndexedState(void*);
struct Payload { unsigned char index:3; unsigned char segment:1; unsigned char other:4; unsigned char bytes[15]; };
struct Packet { unsigned char pad[4]; Payload payload; };
// Original: arm9/ov017 @ 0x021CCD10; symbol: func_ov017_021ccd10; size: 0x9C.
extern "C" void GameState_ApplyPacketObjectByteSegment(void* unused,Packet* packet,void* state) {
 Payload* payload=&packet->payload;
 void* object=GameState_GetObjectWithFlag100(state,payload->index);
 if(!object) return;
 unsigned char* dest=GameObject_GetLinkedIndexedState(object);
 if(!dest) return;
 if(payload->segment==0) {
  for(int i=0;i<15;i++) (dest+i)[0x464]=payload->bytes[i];
 } else if(payload->segment==1) {
  for(int i=0;i<12;i++) (dest+(i+15))[0x464]=payload->bytes[i];
 }
}
