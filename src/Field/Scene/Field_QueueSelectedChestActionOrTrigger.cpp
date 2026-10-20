#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/Zone3DContainers.h>
#pragma force_active on
ARM
struct State { int pad[12]; int count; };
extern "C" void* GameState_GetSerializedProgressState();
extern "C" bool Script_ExecuteFirstSatisfiedTriggerGroup(void*,int,State*);
extern "C" void Script_DispatchResultCommandsToWorld(State*);
extern "C" void FieldChest_InitializeOpenCommand(void*);
extern "C" unsigned char GameState_ReadFirstObjectIndex(GameState*);
extern "C" void LinkedQueue_AppendAndMarkActive(unsigned int*,unsigned int);
// Original: arm9/ov017 @ 0x0219922C; symbol: func_ov017_0219922c; size: 0xF0.
// Executes a selected chest's trigger or queues its open command with leader and facing information.
extern "C" void Field_QueueSelectedChestActionOrTrigger(unsigned char* owner)
{
    GameState* game=GameState::GetInstance();
    ZoneChestEntry* chest=*(ZoneChestEntry**)(owner+0x36bc);
    unsigned short selected=*(unsigned short*)(owner+0x36b6);
    short angle=*(short*)(owner+0x36c6);
    int canOpen=chest->state==1;
    if(!canOpen) {
        State result;
        void* progress=GameState_GetSerializedProgressState();
        result.pad[8]=chest->unknown_1c;
        if(Script_ExecuteFirstSatisfiedTriggerGroup(progress,18,&result)) Script_DispatchResultCommandsToWorld(&result);
    } else {
        FieldChest_InitializeOpenCommand(*(void**)(owner+0x3b24));
        (*(unsigned char**)(owner+0x3b24))[0xa]=selected;
        (*(unsigned char**)(owner+0x3b24))[8]=GameState_ReadFirstObjectIndex(game);
        *(short*)(*(unsigned char**)(owner+0x3b24)+0x10)=fix32ReduceAngle0To2Pi(angle+0x3244);
        *(Vector3i*)(*(unsigned char**)(owner+0x3b24)+0x14)=chest->position;
        if((unsigned char)chest->unknown_17==2) (*(unsigned char**)(owner+0x3b24))[0x20]=1;
        LinkedQueue_AppendAndMarkActive(*(unsigned int**)(owner+0x36fc),*(unsigned int*)(owner+0x3b24));
    }
}
