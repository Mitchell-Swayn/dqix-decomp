#include <globaldefs.h>
#include <GameState/GameState.h>
#pragma force_active on
ARM
struct Object;
struct SkillPointState { char unknown[0x464]; unsigned char points[27]; };
struct SkillPointPayload {
    unsigned char member:3;
    unsigned char fragment:1;
    unsigned char reserved:4;
    unsigned char points[15];
};
struct SkillPointPacket { unsigned char command; char reserved[3]; SkillPointPayload payload; };
extern "C" GameObject* GameState_GetObjectWithFlag100(GameState*,int);
extern "C" unsigned GameObject_GetLinkedIndexedState(int);
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(Object*,const void*,short);
// Original: arm9/ov017 @ 0x021CCC34; symbol: func_ov017_021ccc34; size: 0xDC.
// Queues all 27 skill-line point totals as fifteen-byte and twelve-byte command-fourteen fragments.
extern "C" void PartySync_QueueSkillLinePointTotals(int index)
{
    GameObject* object=GameState_GetObjectWithFlag100(GameState::GetInstance(),index);
    if(!object) return;
    SkillPointState* state=(SkillPointState*)GameObject_GetLinkedIndexedState((int)object);
    if(!state) return;
    Object* queue=(Object*)Network_GetCommandRecordPool();
    SkillPointPacket packet;
    packet.payload.member=(unsigned char)index;
    packet.command=14;
    packet.payload.fragment=0;
    for(int i=0;i<15;++i) packet.payload.points[i]=state->points[i];
    Network_QueueOutgoingRecord(queue,&packet,0);
    packet.payload.fragment=1;
    for(int i=0;i<12;++i) packet.payload.points[i]=state->points[i+15];
    Network_QueueOutgoingRecord(queue,&packet,0);
}
