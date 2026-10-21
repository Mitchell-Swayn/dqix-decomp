struct WindowCanvasOwner;
struct WindowCanvasRecord;
struct Owner;
#include <globaldefs.h>
#include <GameState/GameState.h>
#include <std_library_functions.h>
ARM

struct ActionIdWord {
    unsigned id : 12;
    unsigned rest : 20;
};

struct ActionCostWord {
    unsigned cost : 8;
    unsigned rest : 24;
};

extern "C" {
unsigned int TextContext_GetSharedInstance();
GameObject* GameState_GetObjectWithFlag100(GameState* state, int index);
int Text_AppendFormatString(char* p, const char* text);
void TextLayout_ResetFormattingWorkspace(signed char* object);
void TextContext_SetNumericArgument(unsigned int* p, int i, unsigned int v);
void TextMarkup_ExpandAndWrapText(void* p, int unused, void* a, void* b, int c, int d, unsigned flags);
int Window_PushTextCanvas(...);
int Window_ReplaceCanvasTextById(Owner* self, unsigned id, void* data, unsigned arg, unsigned char flag);
WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner* self, unsigned id);
void Text_CopyActionDescriptionByKey(int count, char* out);
int Party_ApplyMPCostDiscount(int object, int value);
void* Text_LookupStandardString(unsigned key);
int Combat_IsMpCostWaived(char* p);
unsigned int BattleMenu_GetSpellChoice(unsigned char* table, int index);
}

// Original: arm9/ov000 @ 0x02178D28; symbol: func_ov000_02178d28; size: 0x200.
// Builds wrapped description text for the selected spell record and either replaces
// ready canvas 0x22 or pushes a new canvas using that record's coordinates. Numeric
// args are the MP cost (waived -> 0; action id 0x28 with current MP below 0x14 -> 0x14;
// cost byte 0xff -> current MP; otherwise discounted) and current MP at +0xe.
extern "C" void BattleMenu_UpdateSpellDescriptionWindow(char* self, char* record) {
    if (!record)
        return;

    int index = *(signed char*)(record + 0x20);
    char* scratch = *(char**)(TextContext_GetSharedInstance() + 0x5c);
    memset(scratch, 0, 0x960);
    GameState* game = GameState::GetInstance();
    char* choice = (char*)BattleMenu_GetSpellChoice((unsigned char*)record, index);
    if (!choice)
        return;
    GameObject* combatant = game->GetCombatantByIndex(*(int*)(record + 0x4c));
    if (!combatant)
        return;
    GameObject* object = GameState_GetObjectWithFlag100(game, *(int*)(record + 0x4c));
    if (!object)
        return;

    Text_CopyActionDescriptionByKey(((ActionIdWord*)(choice + 4))->id, scratch);
    char wrap[0x800];
    TextMarkup_ExpandAndWrapText((void*)TextContext_GetSharedInstance(), 0xa, scratch, wrap, 0x72, 0, 0);
    char* text = wrap;
    unsigned int* context = (unsigned int*)TextContext_GetSharedInstance();
    TextLayout_ResetFormattingWorkspace((signed char*)context);

    unsigned cost;
    if (Combat_IsMpCostWaived((char*)combatant) != 0)
        cost = 0;
    else if (((ActionIdWord*)(choice + 4))->id == 0x28 && *(short*)(record + 0xe) < 0x14)
        cost = 0x14;
    else {
        unsigned byte = ((ActionCostWord*)(choice + 8))->cost;
        if (byte >= 0xff)
            cost = (unsigned)*(short*)(record + 0xe);
        else
            cost = (unsigned)Party_ApplyMPCostDiscount((int)object, (int)byte);
    }

    TextContext_SetNumericArgument(context, 0, cost);
    TextContext_SetNumericArgument(context, 1, (unsigned)*(short*)(record + 0xe));
    Text_AppendFormatString(text, (const char*)Text_LookupStandardString(0x3ec));

    char* panel = self + 0x188;
    if (Window_FindActiveCanvasById((WindowCanvasOwner*)panel, 0x22)) {
        Window_ReplaceCanvasTextById((Owner*)panel, 0x22, text, 1, 0);
        return;
    }

    int x = *(int*)(record + 0x44);
    int y = *(int*)(record + 0x48);
    *(short*)(panel + 0xa0) = 0x10;
    *(short*)(panel + 0xa2) = 0xa;
    *(short*)(panel + 0xa4) = (short)((x >> 3) + 0x10);
    *(short*)(panel + 0xa6) = (short)(y >> 3);
    *(short*)(panel + 0xa8) = 7;
    *(short*)(panel + 0xaa) = 6;
    *(short*)(panel + 0xac) = 0xa;
    *(short*)(panel + 0xae) = 0xe;
    *(unsigned char*)(panel + 0xb1) = 0x22;
    Window_PushTextCanvas(panel, text, 0, 0, 0, 1, 0, 0);
}
