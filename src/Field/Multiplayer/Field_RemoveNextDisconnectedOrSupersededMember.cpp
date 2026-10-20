#include <globaldefs.h>
#include <GameState/GameState.h>
#pragma force_active on
ARM
extern "C" void* Network_GetConnectionManager();
extern "C" GameObject* GameState_GetObjectWithFlag200ByIndex(GameState*,int);
extern "C" unsigned Network_TestMemberDisconnectFlag(char*,int);
extern "C" void Field_RemoveRemoteMemberAndSynchronizationState(char*,int,int);
// Original: arm9/ov017 @ 0x02195658; symbol: func_ov017_02195658; size: 0xF0.
// Removes the first disconnected or superseded remote member and cancels its pending join command.
extern "C" int Field_RemoveNextDisconnectedOrSupersededMember(void* context)
{
    unsigned char* owner=(unsigned char*)context;
    GameState* game=GameState::GetInstance();
    char* connection=(char*)Network_GetConnectionManager();
    for(int member=1;member<4;++member) {
        int remove=0;
        int notify=1;
        GameObject* object=GameState_GetObjectWithFlag200ByIndex(game,member);
        unsigned char* join=*(unsigned char**)(owner+0x441c);
        if(join[0]==1 && join[2]==member) {
            if(object) { remove=1; notify=0; }
        }
        if(Network_TestMemberDisconnectFlag(connection,member)) remove=1;
        if(remove) {
            Field_RemoveRemoteMemberAndSynchronizationState((char*)owner,member,notify);
            if(notify && (*(unsigned char**)(owner+0x441c))[0]) {
                join=*(unsigned char**)(owner+0x441c);
                if(join[2]==member) {
                    join[0]=0;
                    join[1]=0;
                    unsigned char* command=*(unsigned char**)(owner+0x3b30);
                    if(command[3]) command[8]=1;
                }
            }
            return member;
        }
    }
    return -1;
}
