#include <globaldefs.h>
#include <GameState/GameState.h>
ARM

struct State { char pad[0x98]; void* a; void* b; char gap[0x13]; unsigned char mode; };

struct BattleOptionWord {
    unsigned pad : 30;
    unsigned flag : 1;
    unsigned rest : 1;
};

extern "C" {
void* GameState_GetIndexList(GameState* state);
ARM void Window_PopCanvasesAndResetSelection(State* p, int flag);
int Selection_ReadEnabledIndexFromControl(void* p);
void SoundSfx_StartCurrentSequenceArchiveEntry(char* p, int a, void* b);
int BattleMenu_RefreshExistingPanel(...);
bool BattleMenu_TestConfirmInputAfterDelay(unsigned char* p, int delay);
int BattleMenu_TestCancelInput(void* owner);
void BattleMenu_ConfigureGlobalCommandSelection(char* self, int value, int option);
void GameState_QueueIndexedObjectFieldSnapshot();
// Original data: arm9/main @ 0x2108760; symbol: Main_UnknownRoleZeroInitializedStorage.
unsigned char Main_UnknownRoleZeroInitializedStorage[];
}

// Original: arm9/ov000 @ 0x0217DCF0; symbol: func_ov000_0217dcf0; size: 0x174.
// Sets menu flag 0x100, stores the current selection, and on confirm toggles
// bit 30 of the selected party member's stats word at +0x134/+0x3c before
// refreshing the panel; on cancel pops the selection history.
extern "C" void BattleMenu_TogglePartyMemberBattleOption(char* self, int value, int option) {
    *(unsigned short*)(self + 0x1d72) = *(unsigned short*)(self + 0x1d72) | 0x100;
    *(signed char*)(self + 0x1d6b) = (signed char)Selection_ReadEnabledIndexFromControl(self + 0x188);
    if (BattleMenu_TestConfirmInputAfterDelay((unsigned char*)self, 0)) {
        SoundSfx_StartCurrentSequenceArchiveEntry((char*)Main_UnknownRoleZeroInitializedStorage, 1, 0);
        GameState* game = GameState::GetInstance();
        unsigned char* list = (unsigned char*)GameState_GetIndexList(game);
        signed char index = *(signed char*)(self + 0x1d6b);
        if (index < list[0xf7c]) {
            signed char slot = *(signed char*)(self + index + 0x70);
            signed char memberIndex = (signed char)*(int*)(self + slot * 0x448 + 0x9a4);
            GameObject* member = game->GetPartyMemberByIndex(memberIndex);
            if (member) {
                int cleared = 0;
                BattleOptionWord* word = (BattleOptionWord*)(*(char**)((char*)member + 0x134) + 0x3c);
                unsigned short flag = word->flag;
                flag = flag + 1;
                flag = flag & 1;
                word->flag = flag;
                BattleMenu_RefreshExistingPanel(
                    self,
                    cleared,
                    *(signed char*)(self + *(signed char*)(self + 0x1d68) + 0x1d60),
                    value,
                    option,
                    0);
                GameState_QueueIndexedObjectFieldSnapshot();
            }
        }
    } else if (BattleMenu_TestCancelInput(self)) {
        Window_PopCanvasesAndResetSelection((State*)(self + 0x188), 0);
        *(self + *(signed char*)(self + 0x1d68) + 0x1d60) = 0;
        *(signed char*)(self + 0x1d68) = *(signed char*)(self + 0x1d68) - 1;
        BattleMenu_ConfigureGlobalCommandSelection(self, value, option);
    }
}
