#include <globaldefs.h>
ARM
class GameState; class GameObject;
extern "C" GameObject* GameState_FindIndexedObjectWithFlag1000(GameState* state, int index);
extern "C" void PartyStatus_ClearMemberDisplayMask(unsigned char* p,unsigned int bit);
extern "C" int Network_GetLocalMemberId(char* p);
extern "C" int GameObject_GetAssociatedPartyMemberIndex(GameObject*);
extern "C" void Field_RebuildMemberFollowChain(void*,int,int,int,int);
extern "C" void Field_RebuildDisplayedAndProtagonistRosters(void*);
// Original: arm9/ov017 @ 0x021CFF0C; symbol: func_ov017_021cff0c; size: 0x80.
extern "C" void GameState_ApplyMatchingSlotClearMessage(void *unused, unsigned char *input, GameState *state, char *context, char *connection) {
    if (input[4] == Network_GetLocalMemberId(connection)) {
        Field_RebuildDisplayedAndProtagonistRosters(context);
        PartyStatus_ClearMemberDisplayMask(*(unsigned char **)(context + 0x36d0),input[5]);
        int value = input[5];
        GameObject *object = GameState_FindIndexedObjectWithFlag1000(state,value);
        if (object) value = GameObject_GetAssociatedPartyMemberIndex(object);
        Field_RebuildMemberFollowChain(context,value,1,1,1);
    }
}
