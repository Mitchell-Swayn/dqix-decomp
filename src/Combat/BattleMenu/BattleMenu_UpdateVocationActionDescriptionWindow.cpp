struct WindowCanvasOwner;
struct WindowCanvasRecord;
struct Owner;
struct Record;
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
Record* BattleMenu_FindActionDefinition(unsigned char* p, unsigned int id);
extern unsigned short BattleMenuUpdateVocationActionDescriptionWindow_UnknownRoleDataReferences[];
}

// Original: arm9/ov000 @ 0x02179CDC; symbol: func_ov000_02179cdc; size: 0x1fc.
// Builds wrapped description text for the party member's current vocation action
// (looked up through the vocation-indexed action-id table) and either replaces ready
// canvas 0x16 or pushes a new canvas using the record's coordinates. Numeric args
// are the discounted MP cost and current MP at +0xe.
extern "C" void BattleMenu_UpdateVocationActionDescriptionWindow(char* self, char* record) {
    if (!record)
        return;

    char* scratch = *(char**)(TextContext_GetSharedInstance() + 0x5c);
    memset(scratch, 0, 0x960);
    GameState* game = GameState::GetInstance();
    GameObject* combatant = game->GetCombatantByIndex(*(int*)(record + 0x4c));
    if (!combatant)
        return;
    GameObject* member = game->GetPartyMemberByIndex(*(int*)(record + 0x4c));
    if (!member)
        return;
    char* vocation = *(char**)((char*)member + 0x150);
    Record* action = BattleMenu_FindActionDefinition((unsigned char*)record,
        BattleMenuUpdateVocationActionDescriptionWindow_UnknownRoleDataReferences[*(int*)(vocation + 0x950)]);
    GameObject* object = GameState_GetObjectWithFlag100(game, *(int*)(record + 0x4c));
    if (!object)
        return;

    Text_CopyActionDescriptionByKey(((ActionIdWord*)((char*)action + 4))->id, scratch);
    char wrap[0x800];
    TextMarkup_ExpandAndWrapText((void*)TextContext_GetSharedInstance(), 0xa, scratch, wrap, 0x72, 0, 0);
    char* text = wrap;
    unsigned int* context = (unsigned int*)TextContext_GetSharedInstance();
    TextLayout_ResetFormattingWorkspace((signed char*)context);

    unsigned cost;
    if (Combat_IsMpCostWaived((char*)combatant) != 0)
        cost = 0;
    else {
        unsigned byte = ((ActionCostWord*)((char*)action + 8))->cost;
        if (byte >= 0xff)
            cost = (unsigned)*(short*)(record + 0xe);
        else
            cost = (unsigned)Party_ApplyMPCostDiscount((int)object, (int)byte);
    }

    TextContext_SetNumericArgument(context, 0, cost);
    TextContext_SetNumericArgument(context, 1, (unsigned)*(short*)(record + 0xe));
    Text_AppendFormatString(text, (const char*)Text_LookupStandardString(0x3ec));

    char* panel = self + 0x188;
    if (Window_FindActiveCanvasById((WindowCanvasOwner*)panel, 0x16)) {
        Window_ReplaceCanvasTextById((Owner*)panel, 0x16, text, 1, 0);
        return;
    }

    int x = *(int*)(record + 0x44);
    int y = *(int*)(record + 0x48);
    *(short*)(panel + 0xa0) = 0x10;
    *(short*)(panel + 0xa2) = 0xa;
    *(short*)(panel + 0xa4) = (short)((x >> 3) + 0x10);
    *(short*)(panel + 0xa6) = (short)((short)(y >> 3) + 3);
    *(short*)(panel + 0xa8) = 7;
    *(short*)(panel + 0xaa) = 6;
    *(short*)(panel + 0xac) = 0xa;
    *(short*)(panel + 0xae) = 0xe;
    *(unsigned char*)(panel + 0xb1) = 0x16;
    Window_PushTextCanvas(panel, text, 1, 0, 0, 1, 0, 0);
}
