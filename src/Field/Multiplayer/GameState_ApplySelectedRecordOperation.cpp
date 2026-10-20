#include <globaldefs.h>
ARM

extern "C" void GameState_SetProgressChapter(void*, int);
extern "C" void GameState_SetProgressStage(void*, int);
extern "C" void GameState_SetProgressStep(void*, int);
extern "C" int Network_GetLocalMemberId(char*);
extern "C" void* GameState_GetSerializedProgressState();
extern "C" void BitArray_SetIndexedBoolean(void*, void*, unsigned, int);
extern "C" void Script_ClearCategoryProgressFlags(char*, int);
extern "C" void Script_ClearCategorySecondaryProgressFlags(char*, int);

struct ActionFlags { unsigned char operation : 7; unsigned char bypassGate : 1; };
struct RecordAction {
    unsigned char unknown[4];
    ActionFlags flags;
    short value;
    unsigned short bit;
};

// Original: arm9/ov017 @ 0x021CE174; symbol: GameState_ApplySelectedRecordOperation; size: 0x124.
// Applies one selected-record operation; the command's top bit bypasses a signed-field gate.
extern "C" void GameState_ApplySelectedRecordOperation(void*, RecordAction* command, void* state, void*, char* gate)
{
    unsigned gateBit = ((unsigned)((unsigned char*)command)[4] << 24) >> 31;
    if (gateBit == 0 && Network_GetLocalMemberId(gate) == 0)
        return;

    char* global = (char*)GameState_GetSerializedProgressState();
    switch (command->flags.operation) {
    case 0:
        GameState_SetProgressChapter(state, command->value);
        GameState_SetProgressStage(state, 1);
        GameState_SetProgressStep(state, 1);
        Script_ClearCategoryProgressFlags(global, (unsigned char)global[0x332]);
        break;
    case 1:
        GameState_SetProgressStage(state, command->value);
        GameState_SetProgressStep(state, 1);
        Script_ClearCategorySecondaryProgressFlags(global, (unsigned char)global[0x332]);
        break;
    case 2:
        GameState_SetProgressStep(state, command->value);
        break;
    case 3:
        BitArray_SetIndexedBoolean(global, global + 0x8c, command->bit, command->value);
        break;
    case 4: {
        unsigned selected = (unsigned char)global[0x332];
        BitArray_SetIndexedBoolean(global, global + selected * 28 + 3, command->bit, command->value);
        break;
    }
    case 5: {
        unsigned selected = (unsigned char)global[0x332];
        BitArray_SetIndexedBoolean(global, global + selected * 28 + 16, command->bit, command->value);
        break;
    }
    }
}
