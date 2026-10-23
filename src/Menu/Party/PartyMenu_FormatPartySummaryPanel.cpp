#include <globaldefs.h>
ARM
// Preserve the original independent narrowing and reload operations.
#pragma opt_propagation off
#pragma force_active on
#define WORD(o) (*(int*)(self + (o)))
#define HALF(o) (*(short*)(self + (o)))
#define BYTE(o) (*(unsigned char*)(self + (o)))
#define SBYTE(o) (*(signed char*)(self + (o)))
#define POINTER(o) (*(char**)(self + (o)))
extern "C" void* ResourceStringTable_GetTextByKey(void*, void*);
extern "C" int Text_AppendFormatString(char*, const char*);
extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const char*, int);
extern "C" int TextMarkup_AppendFrameTag(char*, int, int, int, int, int);
extern "C" int TextMarkup_AppendCursorTag(char*, int);
extern "C" int Text_AppendFormattedXYPair(char*, int, int);
extern "C" int AppendFormattedNumberAndText(char*, const char*, int);
extern "C" int TextMarkup_AppendPaletteTag(char*, int);
extern "C" int TextMarkup_AppendXPositionTag(char*, int);
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*, int, const char*);
struct SummaryCurrentStats { char unknown00[4]; unsigned short hp, mp; };
struct SummaryBaseStats { char name[0x30]; unsigned short hp, mp, strength, resilience; };
struct SummaryMember { char unknown00[0x130]; SummaryCurrentStats* current; SummaryBaseStats* base; };
extern "C" char* TextContext_GetSharedInstance();
extern "C" char* _ZN9GameState11GetInstanceEv();
extern "C" char* GameState_GetObjectWithFlag100(void*, int);
extern "C" char* GameObject_GetLinkedIndexedState(void*);
extern "C" void TextLayout_ResetFormattingWorkspace(void*);
extern "C" void TextContext_SetStringArgument(void*, int, const char*);
extern "C" void TextContext_SetNumericArgument(void*, int, unsigned);
extern "C" void TextContext_SetNumericArgumentWidth(char*, int, int);
extern "C" void TextContext_SetNumericArgumentAlignment(char*, int, int);
extern "C" void TextMarkup_ExpandAndWrapText(void*, int, void*, void*, int, int, unsigned);
extern "C" char* GameResources_GetInstance();
extern "C" int GameResources_GetAlternatePartyModel(void*);
extern "C" int sprintf(char*, const char*, ...);
extern "C" void __clear(void*, unsigned);
// Original data: arm9/ov002 @ 0x0216D2A1; symbol: data_ov002_0216d2a1. Format: <tc>%d.
extern "C" char PartyMenu_FormatPartySummaryPanel_FormatTcD[];
// Original: arm9/ov002 @ 0x0215E644; symbol: func_ov002_0215e644; size: 0x2bc.
// Formats current member statistics and centered names into the party summary template.
extern "C" void PartyMenu_FormatPartySummaryPanel(void* menu, void* output, int alternateMode)
{
    char* self = (char*)menu;
    char* out = (char*)output;
    if (!out) return;
    char* context = TextContext_GetSharedInstance();
    SummaryMember* member = (SummaryMember*)GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(), SBYTE(0x1c20));
    if (!member) return;
    char* linked = GameObject_GetLinkedIndexedState(member);
    if (!linked) return;
    TextLayout_ResetFormattingWorkspace(context);
    TextContext_SetStringArgument(context, 0, (char*)member->base);
    int nameX = (64 - TextLayout_ComputeWidthWithGlyphSpacing((char*)member->base, 0)) >> 1;
    unsigned stat1 = member->current->hp;
    TextContext_SetNumericArgument(context, 0, stat1);
    unsigned stat2 = member->base->hp;
    TextContext_SetNumericArgument(context, 1, stat2);
    unsigned stat3 = member->current->mp;
    TextContext_SetNumericArgument(context, 2, stat3);
    unsigned stat4 = member->base->mp;
    TextContext_SetNumericArgument(context, 3, stat4);
    TextContext_SetNumericArgument(context, 4, *(unsigned short*)(linked + *(int*)(linked + 0x950) * 2 + 0x16c));
    unsigned stat5 = member->base->strength;
    TextContext_SetNumericArgument(context, 5, stat5);
    unsigned stat6 = member->base->resilience;
    TextContext_SetNumericArgument(context, 6, stat6);
    TextContext_SetNumericArgument(context, 7, (*(unsigned*)linked << 12) >> 22);
    int modelIndex = *(int*)(linked + 0x950);
    char* resources = GameResources_GetInstance();
    if (GameResources_GetAlternatePartyModel(resources)) modelIndex = 0;
    const char* modelName = (const char*)ResourceStringTable_GetTextByKey(self + 0x20, (void*)(int)(short)(modelIndex + 0x834));
    int modelX = (64 - TextLayout_ComputeWidthWithGlyphSpacing(modelName, 0)) >> 1;
    if (GameResources_GetAlternatePartyModel(resources)) TextContext_SetStringArgument(context, 1, modelName);
    else if (*(int*)((char*)member + 0x1c4) == 0) TextContext_SetStringArgument(context, 1, modelName);
    char text[1024];
    char number[16];
    char marked[32];
    unsigned char rank = *(unsigned char*)(linked + *(int*)(linked + 0x950) + 0x186);
    if (rank) {
        sprintf(number, PartyMenu_FormatPartySummaryPanel_FormatTcD, rank);
        __clear(marked, 32);
        int palette = 5;
        if (rank == 10) palette = 13;
        TextMarkup_AppendPaletteTag(marked, palette);
        Text_AppendFormatString(marked, number);
        TextMarkup_AppendPaletteTag(marked, 15);
        TextContext_SetStringArgument(context, 2, marked);
    }
    for (int i = 0; i < 8; ++i) {
        int width = 3;
        if (i == 4) width = 2;
        TextContext_SetNumericArgumentWidth(context, i, (unsigned char)width);
    }
    for (int i = 0; i < 8; ++i) TextContext_SetNumericArgumentAlignment(context, i, 1);
    const char* format = (const char*)ResourceStringTable_GetTextByKey(self + 0x20, (void*)0x7d0);
    sprintf(text, format, nameX, modelX);
    TextMarkup_ExpandAndWrapText(context, 10, text, out, 256, 0, 0);
}
