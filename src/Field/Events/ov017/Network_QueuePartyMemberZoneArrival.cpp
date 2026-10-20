#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
struct Object;
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(Object*,const void*,short);
extern "C" void Field_ResolveObjectZoneCollision(void*,void*);
struct PositionPayload {unsigned short identifier;unsigned char index,flag;unsigned short value;short x,y,z,angle;unsigned short unknown;};
struct PositionCommand {unsigned char opcode,unknown1;unsigned short unknown2;PositionPayload payload;};
// Original: arm9/ov017 @ 0x021C4854; symbol: Network_QueuePartyMemberZoneArrival; size: 0x9C.
// Queues opcode0x37 with position components shifted right5, then enables flag0x4000000 on the selected game object.
// The final helper's role and untouched command bytes remain uncertain.
extern "C" void Network_QueuePartyMemberZoneArrival(unsigned short* identifier,unsigned char index,unsigned short value,const Vector3i* position,short angle,unsigned char flag) {
 unsigned short id=*identifier;
 Object* queue=(Object*)Network_GetCommandRecordPool();
 PositionCommand command;
 command.opcode=0x37;
 PositionPayload* payload=&command.payload;
 payload->identifier=id;payload->index=index;payload->value=value;
 payload->x=position->x>>5;payload->y=position->y>>5;payload->z=position->z>>5;
 payload->angle=angle;payload->flag=flag;
 Network_QueueOutgoingRecord(queue,&command,0);
 GameObject* object=GameState::GetInstance()->GetUnknownGameObject();
 object->obj3D_.EnableFlag(0x4000000);
 Field_ResolveObjectZoneCollision(object,0);
}
