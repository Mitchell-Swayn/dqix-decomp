#include <globaldefs.h>
ARM
class GameState; class GameObject;
extern "C" GameObject* GameState_FindIndexedObjectWithFlag1000(GameState* state, int index);
extern "C" void ClearOneOfFourFlagBitsAtOffset75D(unsigned char* p,unsigned int bit);
extern "C" int ReadIndexedSignedField1038(char* p);
extern "C" int ReadFieldAtOffset2D0(GameObject*);
extern "C" void Unclassified_InvokeRoutineWithLocalOutputAndZeroStatus(void*,int,int,int,int);
extern "C" void BuildActiveAndProtagonistSlotLists(void*);
// Original: arm9/ov017 @ 0x021CFF0C; symbol: func_ov017_021cff0c; size: 0x80.
extern "C" void GameState_ApplyMatchingSlotClearMessage(void *unused, unsigned char *input, GameState *state, char *context, char *connection) {
    if (input[4] == ReadIndexedSignedField1038(connection)) {
        BuildActiveAndProtagonistSlotLists(context);
        ClearOneOfFourFlagBitsAtOffset75D(*(unsigned char **)(context + 0x36d0),input[5]);
        int value = input[5];
        GameObject *object = GameState_FindIndexedObjectWithFlag1000(state,value);
        if (object) value = ReadFieldAtOffset2D0(object);
        Unclassified_InvokeRoutineWithLocalOutputAndZeroStatus(context,value,1,1,1);
    }
}
