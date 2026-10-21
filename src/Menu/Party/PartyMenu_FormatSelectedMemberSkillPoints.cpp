#include <globaldefs.h>
#include <GameState/GameState.h>
ARM

typedef unsigned int undefined4;

extern "C" {
GameObject* GameState_GetObjectWithFlag100(GameState* state, int index);
undefined4 GameObject_GetLinkedIndexedState(int param_1);
void PartyMenu_CopySelectableMemberIndices(char* self, int* output);
void* ResourceStringTable_GetTextByKey(void* a, void* b);
void* __clear(void* destination, unsigned int count);
void Graphics_AppendCenteredFormattedText(char** text, const char* format, unsigned int font);
int AppendFormattedNumberAndText(char* p, const char* text, int n);
unsigned int TextContext_GetSharedInstance();
void TextLayout_ResetFormattingWorkspace(signed char* object);
void TextContext_SetNumericArgument(unsigned int* p, int i, unsigned int v);
void TextContext_SetNumericArgumentWidth(char* p, int i, int v);
void TextContext_SetNumericArgumentAlignment(char* p, int i, int v);
int TextMarkup_AppendHTag(char* p, int n);
void TextMarkup_ExpandAndWrapText(void* p, int unused, void* a, void* b, int c, int d, unsigned flags);
int Text_AppendFormatString(char* p, const char* text);
}

// Original: arm9/ov002 @ 0x021605D4; symbol: func_ov002_021605d4; size: 0x160.
// Formats the selected skill-point member's centered title and remaining-point
// numeric text into the output buffer.
extern "C" void PartyMenu_FormatSelectedMemberSkillPoints(char* self, char* out) {
    char frame[0xd4];
    int index;
    int valid;
    undefined4 linked;
    void* titleText;
    unsigned int ctx;

    if (out == 0)
        return;

    GameState* state = GameState::GetInstance();
    short cursor = *(short*)((self + 0x1c00) + 8);
    PartyMenu_CopySelectableMemberIndices(self, (int*)(frame + 0x44));
    index = ((int*)(frame + 0x44))[cursor];
    if (index >= 0 && index <= 3)
        valid = 1;
    else
        valid = 0;
    if (valid == 0)
        return;
    GameObject* member = GameState_GetObjectWithFlag100(state, index);
    if (member == 0)
        return;
    linked = GameObject_GetLinkedIndexedState((int)member);
    if (linked == 0)
        return;
    titleText = ResourceStringTable_GetTextByKey(self + 0x20, (void*)0x1005);
    __clear(frame + 0x54, 0x80);
    *(char**)frame = frame + 0x54;
    Graphics_AppendCenteredFormattedText((char**)frame, (const char*)titleText, 0);
    AppendFormattedNumberAndText(out, frame + 0x54, 0x10);
    ctx = TextContext_GetSharedInstance();
    TextLayout_ResetFormattingWorkspace((signed char*)ctx);
    TextContext_SetNumericArgument((unsigned int*)ctx, 0, *(unsigned short*)((char*)linked + 0x564));
    TextContext_SetNumericArgumentWidth((char*)ctx, 0, 4);
    TextContext_SetNumericArgumentAlignment((char*)ctx, 0, 1);
    __clear(frame + 4, 0x40);
    TextMarkup_AppendHTag(out, -1);
    TextMarkup_ExpandAndWrapText(
        (void*)ctx,
        8,
        ResourceStringTable_GetTextByKey(self + 0x20, (void*)0x1006),
        frame + 4,
        0x100,
        0,
        0);
    Text_AppendFormatString(out, frame + 4);
}
