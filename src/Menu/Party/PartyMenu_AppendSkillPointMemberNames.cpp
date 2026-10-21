#include <globaldefs.h>
#include <GameState/GameState.h>
ARM

extern "C" {
GameObject* GameState_GetObjectWithFlag100(GameState* state, int index);
void PartyMenu_CopySelectableMemberIndices(char* self, int* output);
int TextMarkup_AppendFrameTag(char* p, int a0, int a1, int a2, int a3, int a4);
int TextMarkup_AppendCursorTag(char* out, int value);
void* ResourceStringTable_GetTextByKey(void* a, void* b);
int AppendFormattedNumberAndText(char* p, const char* text, int n);
int Graphics_SelectObjectRatioColor(char* self, int index, int check, int blocked, unsigned char special);
int TextMarkup_AppendPaletteTag(char* p, int a0);
int Text_AppendFormattedIntegerAndStringFragment(char* p, int n, const char* text);
int Text_AppendFormatString(char* p, const char* text);
}

// Original: arm9/ov002 @ 0x0216049C; symbol: func_ov002_0216049c; size: 0x138.
// Appends skill-point member names for selectable indices 0-3, coloring each
// live object and separating names with the menu delimiter.
extern "C" void PartyMenu_AppendSkillPointMemberNames(char* self, char* out, int prefix) {
    int indices[4];
    register short cursor;
    register GameState* state;
    register GameObject* member;
    register int index;
    register int i;
    int valid;

    if (out == 0)
        return;

    state = GameState::GetInstance();
    cursor = *(short*)((self + 0x1c00) + 8);
    PartyMenu_CopySelectableMemberIndices(self, indices);
    if (prefix != 0)
        TextMarkup_AppendFrameTag(out, cursor, 8, 5, 5, 5);
    TextMarkup_AppendCursorTag(out, cursor);
    AppendFormattedNumberAndText(
        out,
        (const char*)ResourceStringTable_GetTextByKey(self + 0x20, (void*)0x1004),
        0x10);

    for (i = 0; i < 4; i++) {
        index = indices[i];
        if (index >= 0 && index <= 3)
            valid = 1;
        else
            valid = 0;
        if (valid == 0)
            continue;
        member = GameState_GetObjectWithFlag100(state, index);
        if (member == 0)
            return;
        if (i != 0)
            Text_AppendFormatString(out, *(const char**)(self + 0x1bdc));
        TextMarkup_AppendPaletteTag(
            out,
            Graphics_SelectObjectRatioColor(self, index, 0, 1, 1));
        Text_AppendFormattedIntegerAndStringFragment(out, i, *(const char**)((char*)member + 0x134));
        TextMarkup_AppendPaletteTag(out, 0xf);
    }
}
