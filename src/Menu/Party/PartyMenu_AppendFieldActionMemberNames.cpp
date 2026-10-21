#include <globaldefs.h>
#include <GameState/GameState.h>
ARM

extern "C" {
int TextMarkup_AppendFrameTag(char* p, int a0, int a1, int a2, int a3, int a4);
int TextMarkup_AppendCursorTag(char* out, int value);
void* ResourceStringTable_GetTextByKey(void* a, void* b);
int AppendFormattedNumberAndText(char* p, const char* text, int n);
int Graphics_SelectObjectRatioColor(char* self, int index, int check, int blocked, unsigned char special);
int TextMarkup_AppendPaletteTag(char* p, int a0);
int Text_AppendFormattedIntegerAndStringFragment(char* p, int n, const char* text);
int Text_AppendFormatString(char* p, const char* text);
}

// Original: arm9/ov002 @ 0x0215E9C4; symbol: func_ov002_0215e9c4; size: 0x118.
// Appends a framed title and each field-action member name, coloring by
// Graphics_SelectObjectRatioColor and separating names with the menu delimiter.
extern "C" void PartyMenu_AppendFieldActionMemberNames(char* self, char* out, int prefix) {
    if (out == 0)
        return;

    GameState* state = GameState::GetInstance();
    short cursor = *(short*)(self + 0x1bf8);
    if (prefix != 0)
        TextMarkup_AppendFrameTag(out, cursor, 8, 5, 5, 5);
    TextMarkup_AppendCursorTag(out, cursor);
    AppendFormattedNumberAndText(
        out,
        (const char*)ResourceStringTable_GetTextByKey(self + 0x20, (void*)3),
        0x16);

    for (int i = 0; i < *(signed char*)(self + 0x1c73); i++) {
        GameObject* member = state->GetPartyMemberByIndex(*(signed char*)(self + 0x1c6e + i));
        if (member == 0)
            continue;
        TextMarkup_AppendPaletteTag(
            out,
            Graphics_SelectObjectRatioColor(self, *(signed char*)(self + 0x1c6e + i), 0, 1, 1));
        Text_AppendFormattedIntegerAndStringFragment(out, i, *(const char**)((char*)member + 0x134));
        TextMarkup_AppendPaletteTag(out, 0xf);
        if (i != *(signed char*)(self + 0x1c73) - 1)
            Text_AppendFormatString(out, *(const char**)(self + 0x1bdc));
    }
}
