#include <globaldefs.h>
#include <GameState/GameState.h>
ARM

struct ActionKindWord {
    unsigned pad : 8;
    unsigned kind : 2;
    unsigned rest : 22;
};

struct ActionIdWord {
    unsigned id : 12;
    unsigned rest : 20;
};

extern "C" int BattleMenu_CountEnemyTargetGroups(unsigned char* menu);
extern "C" GameObject* GameState_GetObjectWithFlag100(GameState* state, int index);
extern "C" ARM int CharacterState_GetLearnedSkillMask(unsigned char* state, int bit);
extern "C" int CountFourSlotRecordsWithoutFlag(void* collection);
extern "C" int GameState_CountFourSlotsWithEnabledObjectByte(void* records);
extern "C" int BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[];
extern "C" int BattleMenuRemovePartyMember_UnknownRoleInitializedBytes;

// Original: arm9/ov000 @ 0x02171210; symbol: func_ov000_02171210; size: 0x248.
// Chooses a battle-menu target-selection state from an action record's packed
// targeting fields, party/enemy slot counts, and a learned-skill mask check.
extern "C" int BattleMenu_ResolveActionTargetSelectionState(char* action, char* record) {
    unsigned kind = ((ActionKindWord*)(action + 8))->kind;
    if (kind == 1) {
        record[0x1d] = 0;
        record[0x21] = (char)-1;
        record[0x2e] = (char)-1;
        unsigned hi = *(unsigned*)(action + 0x14) >> 0x1c;
        if (hi == 3)
            return 0x64;
        if (hi == 4) {
            if (BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[2]
                && BattleMenu_CountEnemyTargetGroups(
                       (unsigned char*)BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[2])
                    == 1)
                return 0x64;
        } else {
            if (BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[1] == 1)
                return 0x64;
        }
        *(int*)(record + 0x434) = 0;
        return 0xe;
    }
    if (kind == 2) {
        GameState::GetInstance();
        record[0x1d] = (char)-1;
        record[0x21] = 0;
        unsigned mode = *(unsigned*)(action + 0x14) >> 0x1c;
        if (mode == 6) {
            GameObject* object = GameState_GetObjectWithFlag100(GameState::GetInstance(), *(int*)(record + 0x4c));
            if (object) {
                unsigned char* state = *(unsigned char**)((char*)object + 0x150);
                mode = 2;
                if (CharacterState_GetLearnedSkillMask(state, 0xe6))
                    mode = 3;
            }
        }

        int withoutFlag = 1;
        int withEnabled = 1;
        if (BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[2]) {
            withoutFlag = CountFourSlotRecordsWithoutFlag(
                (void*)BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[2]);
            withEnabled = GameState_CountFourSlotsWithEnabledObjectByte(
                (void*)BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[2]);
        }

        switch (mode) {
        case 3:
        case 4:
            record[0x2e] = (char)*(int*)(record + 0x4c);
            return 0x64;
        case 8:
            if (BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[2]
                && (BattleMenuRemovePartyMember_UnknownRoleInitializedBytes == 1 || withoutFlag == 1
                    || withEnabled == 1))
                return 0x1e;
            return 0x14;
        case 1: {
            unsigned id = ((ActionIdWord*)(action + 4))->id;
            if ((id == 0xb9 || id == 0xb6)
                && BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[2]
                && (BattleMenuRemovePartyMember_UnknownRoleInitializedBytes == 1 || withoutFlag == 1
                    || withEnabled == 1))
                return 0x1e;
            record[0x21] = 0;
            record[0x2e] = (char)*(int*)(record + 0x4c);
            return 0x64;
        }
        case 7:
            if (withEnabled != 1)
                return 0x13;
            record[0x21] = 0;
            record[0x2e] = (char)*(int*)(record + 0x4c);
            return 0x64;
        default:
            if (withEnabled != 1)
                return 0x12;
            record[0x21] = 0;
            record[0x2e] = (char)*(int*)(record + 0x4c);
            return 0x64;
        }
    }
    return 0x64;
}
