#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
#pragma opt_common_subs off

struct Record {
    unsigned int field0;
    unsigned int identifier : 12;
    unsigned int remaining : 20;
};

struct ActionIdWord {
    unsigned id : 12;
    unsigned rest : 20;
};

struct ActionCostWord {
    unsigned cost : 8;
    unsigned rest : 24;
};

extern "C" {
void* GameState_GetIndexList(GameState*);
GameObject* GameState_GetObjectWithFlag100(GameState* state, int index);
int Combat_IsMpCostWaived(char* p);
int Party_ApplyMPCostDiscount(int object, int value);
void* ResourceStringTable_GetTextByKey(void* a,void* b);
void TextSprite_FormatAndUpdateTextReference(unsigned char* object,const char* format);
int BattleMenu_ResolveActionTargetSelectionState(char* action, char* record);
ARM Record* BattleMenu_FindActionDefinition(unsigned char* p,unsigned int id);
void* __clear(void* destination, unsigned int count);
void String_ReplaceBracketedNamesByRowColumnTable(const signed char *input,signed char *output,int row,unsigned unused,unsigned unused2,int column);
void Text_FormatAndConditionallyUppercaseOutput(const char *format,char *out,int id);
}

// Original: arm9/ov000 @ 0x021716D0; symbol: func_ov000_021716d0; size: 0x1d4.
// Confirms the currently selected ability: if the action slot is empty, pushes
// state 0xe and a fallback string; otherwise checks MP (waived/fixed/discounted),
// stores the action id, appends the targeting-history state, and updates the
// description sprite from the action-definition name text.
extern "C" void BattleMenu_ConfirmSelectedAbility(char* self) {
    char* state;
    GameState* game;
    GameObject* object;
    int cost;
    int available;
    int slot;
    char* action;

    state = self + 8;
    slot = *(short*)(state + 0x16);
    if (*(char**)(self + slot * 4 + 0x1a4) == 0) {
        *(signed char*)(state + 0x10) = *(signed char*)(state + 0x10) + 1;
        (state + *(signed char*)(self + 0x18))[8] = 0xe;
        *(signed char*)(state + 0x15) = 0;
        void* text = ResourceStringTable_GetTextByKey(*(void**)(self + 4), (void*)5);
        TextSprite_FormatAndUpdateTextReference((unsigned char*)(self + 0x50), (const char*)text);
        return;
    }

    game = GameState::GetInstance();
    object = GameState_GetObjectWithFlag100(game, *(int*)(self + 0x4c));
    action = *(char**)((char*)((int)self + slot * 4) + 0x1a4);
    cost = ((ActionCostWord*)(action + 8))->cost;
    available = *(short*)(self + 0xe);
    if (object != 0) {
        if (Combat_IsMpCostWaived((char*)object) != 0) {
            cost = 0;
            goto have_cost;
        }
    }

    action = *(char**)((char*)((unsigned)self + (unsigned)(slot * 4)) + 0x1a4);
    if (((ActionCostWord*)(action + 8))->cost >= 0xff)
        cost = 1;
    else
        cost = (unsigned)Party_ApplyMPCostDiscount((int)object, (int)cost);

have_cost:
    action = *(char**)(self + slot * 4 + 0x1a4);
    if (((*(unsigned*)(action+0x2c)<<18)>>28)==6) {
        available = *(int*)((char*)GameState_GetIndexList(game)+0xf6c);
        action = *(char**)(self + slot * 4 + 0x1a4);
        cost = *(short*)(action+0x32);
    }
    if (available < cost) {
        *(signed char*)(state + 0x10) = *(signed char*)(state + 0x10) + 1;
        (state + *(signed char*)(self + 0x18))[8] = 0x1a;
        return;
    }

    *(unsigned short*)(state + 0x1e) =
        (unsigned short)((ActionIdWord*)(action + 4))->id;
    *(signed char*)(state + 0x10) = *(signed char*)(state + 0x10) + 1;
    (state + *(signed char*)(state + 0x10))[8] =
        (char)BattleMenu_ResolveActionTargetSelectionState(*(char**)(self + slot * 4 + 0x1a4), self);

    Record* record = BattleMenu_FindActionDefinition((unsigned char*)self, *(unsigned short*)(state + 0x1e));
    if (record == 0)
        return;

    char expanded[0x80];
    char formatted[0x80];
    __clear(expanded, 0x80);
    __clear(formatted, 0x80);
    String_ReplaceBracketedNamesByRowColumnTable((const signed char*)record->field0, (signed char*)expanded, 1, 0, 0, 0);
    Text_FormatAndConditionallyUppercaseOutput(expanded, formatted, 0);
    TextSprite_FormatAndUpdateTextReference((unsigned char*)(self + 0x50), formatted);
}
