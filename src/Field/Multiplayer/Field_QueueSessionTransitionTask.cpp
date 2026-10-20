#include <globaldefs.h>
#include <GameState/GameState.h>
#pragma force_active on
ARM
struct Node;
extern "C" {
GameResources* GameResources_GetInstance();
void* Zone3D_GetMainInstance();
void FieldPartyEffect_InitializeTransitionCommand(void*);
void FieldPartyEffect_OpenStandardMessagePanel(unsigned char*);
void LinkedQueue_AppendAndMarkActive(unsigned*,unsigned);
void* GameState_ReadUnkF8(GameState*);
void VectorizedMemset(void*,int,unsigned);
int LinkedList_ContainsTag(Node**,int);
void LinkedQueue_RemoveNodeAndResetStatus(int*,int);
void GameState_CopyElapsedTimeIntoTwoConfigurationRecords(int);
void Field_QueueMemberProfileFragments(int,unsigned char,int,int);
}
// Original: arm9/ov017 @ 0x0219577C; symbol: func_ov017_0219577c; size: 0x1C0.
// Queues a session transition, optionally setting the fixed saved destination and cancelling conflicting commands.
extern "C" void Field_QueueSessionTransitionTask(int type,int saveDestination,int suppressMessage)
{
    GameState* game=GameState::GetInstance();
    GameResources* resources=GameResources_GetInstance();
    unsigned* queue=(unsigned*)resources->unknown_ptr_array_36fc[0];
    Zone3D_GetMainInstance();
    unsigned char* command=*(unsigned char**)((unsigned char*)resources+0x3b20);
    if(command[2]) return;
    FieldPartyEffect_InitializeTransitionCommand(command);
    command[0x280]=1;
    command[0x27f]=type;
    command[0x281]=saveDestination==0;
    command[0x282]=suppressMessage==0;
    if(type==0 && suppressMessage) FieldPartyEffect_OpenStandardMessagePanel(command);
    LinkedQueue_AppendAndMarkActive(queue,(unsigned)command);
    if(saveDestination) {
        unsigned char* saved=(unsigned char*)GameState_ReadUnkF8(game);
        VectorizedMemset(saved,0,0x70);
        saved[4]=1;
        saved[8]=1;
        saved[9]=1;
        *(signed char*)(saved+0xb)=-1;
        *(int*)(saved+0x20)=-1;
        *(int*)(saved+0x24)=-1;
        *(int*)(saved+0x28)=-1;
        *(int*)(saved+0x2c)=-1;
        *(short*)(saved+0x1e)=-1;
        saved[0xc]=0;
        *(short*)(saved+0x6c)=-1;
        saved[2]=1;
        *(unsigned short*)saved=0xc3b5;
        saved[7]=1;
        *(short*)(saved+0x1c)=0;
        *(int*)(saved+0x10)=0x48cc;
        *(int*)(saved+0x14)=409;
        *(int*)(saved+0x18)=-1843;
        saved[0x66]=1;
        saved[0x65]=1;
        if(LinkedList_ContainsTag((Node**)queue,78)) LinkedQueue_RemoveNodeAndResetStatus((int*)queue,(int)resources->unknown_ptr_array_3ca4[0]);
        if(LinkedList_ContainsTag((Node**)queue,3)) LinkedQueue_RemoveNodeAndResetStatus((int*)queue,(int)resources->unknown_ptr_array_36fc[4]);
    }
    if(LinkedList_ContainsTag((Node**)queue,64)) LinkedQueue_RemoveNodeAndResetStatus((int*)queue,*(int*)((unsigned char*)resources+0x3b98));
    GameState_CopyElapsedTimeIntoTwoConfigurationRecords(1);
    if(type) Field_QueueMemberProfileFragments(-1,1,1,2);
}
