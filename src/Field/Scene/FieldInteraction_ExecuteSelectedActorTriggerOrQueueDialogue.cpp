#include <globaldefs.h>
#include <GameState/GameState.h>
#pragma force_active on
ARM
struct State { int pad[12]; int count; };
extern "C" void* ActorPool_GetGlobalInstance();
extern "C" unsigned* ActorPool_GetActiveSlot(unsigned**,unsigned);
extern "C" unsigned Actor_GetPlacementDescriptor(int);
extern "C" void* Quest_GetGlobalOrderState();
extern "C" int Quest_ActivateFirstMatchingOrderForActor(void*,unsigned);
extern "C" void* GameState_GetSerializedProgressState();
extern "C" bool Script_ExecuteFirstSatisfiedTriggerGroup(void*,int,State*);
extern "C" void Script_DispatchResultCommandsToWorld(State*);
extern "C" void InitializeType5GraphicsRecord(unsigned char*);
extern "C" void LinkedQueue_AppendAndMarkActive(unsigned*,unsigned);
// Original data: arm9/ov017 @ 0x021D76D8; symbol: data_ov017_021d76d8.
// Packed current interaction target; selected actor slot is signed halfword+2.
extern "C" unsigned char FieldInteractionUpdateActorAndMemberTargets_UnknownRoleInitializedBytes[];
// Original data: arm9/ov017 @ 0x021D83A8; symbol: data_ov017_021d83a8.
// Selected dialogue context identifier, read as an unsigned halfword.
extern "C" unsigned short FieldInteractionUpdateActorAndMemberTargets_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov017 @ 0x021A4CF0; symbol: func_ov017_021a4cf0; size: 0xE0.
// Dispatches a selected actor's kind-zero trigger or queues its standard dialogue command.
extern "C" void FieldInteraction_ExecuteSelectedActorTriggerOrQueueDialogue(unsigned char* owner)
{
    unsigned* actor=ActorPool_GetActiveSlot((unsigned**)ActorPool_GetGlobalInstance(),*(short*)(FieldInteractionUpdateActorAndMemberTargets_UnknownRoleInitializedBytes+2));
    if(!actor) return;
    unsigned short* descriptor=(unsigned short*)Actor_GetPlacementDescriptor((int)actor);
    if(!descriptor) return;
    if((*(unsigned char**)(owner+0x3710))[0x130]) return;
    Quest_ActivateFirstMatchingOrderForActor(Quest_GetGlobalOrderState(),*descriptor&0xff);
    *(unsigned*)((unsigned char*)GameState::GetInstance()+0x5724)=*descriptor;
    State result;
    void* progress=GameState_GetSerializedProgressState();
    result.pad[0]=*descriptor;
    result.pad[5]=FieldInteractionUpdateActorAndMemberTargets_UnknownRoleZeroInitializedStorage[0];
    if(Script_ExecuteFirstSatisfiedTriggerGroup(progress,0,&result)) Script_DispatchResultCommandsToWorld(&result);
    else {
        InitializeType5GraphicsRecord(*(unsigned char**)(owner+0x3710));
        *(unsigned short**)(*(unsigned char**)(owner+0x3710)+0x114)=descriptor;
        *(unsigned*)(*(unsigned char**)(owner+0x3710)+0x124)=FieldInteractionUpdateActorAndMemberTargets_UnknownRoleZeroInitializedStorage[0];
        LinkedQueue_AppendAndMarkActive(*(unsigned**)(owner+0x36fc),*(unsigned*)(owner+0x3710));
    }
}
