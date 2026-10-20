#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
struct Object;
typedef unsigned int undefined4;
extern "C" GameObject *GameState_GetObjectWithFlag100(GameState *, int);
extern "C" undefined4 GameObject_GetLinkedIndexedState(int);
extern "C" void *Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(Object *, const void *, short);
struct SelectedRecordPacket {
 unsigned char opcode; unsigned char padding[3];
 unsigned short objectIndex:3; unsigned short selectedValue:8; unsigned short selection:4; unsigned short flag:1;
 unsigned short field564; unsigned int value; unsigned char field186,first,second; unsigned int unresolvedTail;
};
// Original: arm9/ov017 @ 0x021CC730; symbol: PartySync_QueueCurrentVocationProgress; size: 0x100.
// Queues opcode 10 with selected object fields; source field meanings remain unresolved.
extern "C" void PartySync_QueueCurrentVocationProgress(int index, unsigned short flag, unsigned char first, unsigned char second) {
 GameObject *object=GameState_GetObjectWithFlag100(GameState::GetInstance(),index);
 if(!object)return;
 char *fields=(char *)GameObject_GetLinkedIndexedState((int)object);
 if(!fields)return;
 Object *queue=(Object *)Network_GetCommandRecordPool();
 SelectedRecordPacket packet;
 unsigned selection=*(unsigned *)(fields+0x950);
 packet.opcode=10;
 packet.objectIndex=(unsigned short)index;
 packet.selectedValue=*(unsigned short *)(fields+0x16c+selection*2);
 packet.selection=(unsigned short)*(unsigned *)(fields+0x950);
 packet.value=*(unsigned *)(fields+0x138+selection*4);
 packet.field564=*(unsigned short *)(fields+0x564);
 packet.field186=*(unsigned char *)(fields+0x186+selection);
 packet.flag=flag;
 packet.first=first;
 packet.second=second;
 Network_QueueOutgoingRecord(queue,&packet,0);
}
