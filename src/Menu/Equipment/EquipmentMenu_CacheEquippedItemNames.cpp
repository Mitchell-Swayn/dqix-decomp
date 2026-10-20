#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/Zone3DEmbeddedState.h>
ARM
extern "C" {
unsigned int TextContext_GetSharedInstance();
unsigned Field_GetSharedSubscreenInstance(void* self);
GameObject* GameState_GetObjectWithFlag100(GameState* state, int index);
void* GameObject_GetLinkedStatsOrNull(char* p);
void* ZoneState2754_FindPrimaryRecordByKey(ZoneState2754* state, int key);
void TextEntry_ReleaseGlyphRunReferences(void*, void*, unsigned);
void* __clear(void* destination, unsigned int count);
void Text_FormatAndConditionallyUppercaseOutput(const char* format, char* out, int id);
void TextMarkup_ExpandAndWrapText(void* p, int unused, void* a, void* b, int c, int d, unsigned flags);
void* ResourceStringTable_GetTextByKey(void* a, void* b);
char* String_FindFirstSubstring(char* text, const char* pattern);
void TextLayout_ConvertMarkupToCachedGlyphIndices(void*, const char*, void*, int);
void TextWindow_RenderAndTransferDisplayBuffers(void*, int);
extern unsigned char EquipmentMenuCacheEquippedItemNames_UnknownRoleInitializedBytes[];
extern char EquipmentMenuCacheEquippedItemNames_UnknownRoleInitializedBytes_Variant2[];
}
// Original: arm9/ov005 @ 0x0215AE7C; symbol: func_ov005_0215ae7c; size: 0x224.
// Builds eight equipped-item label glyph buffers from records or fallback strings.
extern "C" void EquipmentMenu_CacheEquippedItemNames(unsigned char* p)
{
    unsigned renderer = TextContext_GetSharedInstance();
    GameState* game = GameState::GetInstance();
    char* resources = (char*)GameResources_GetInstance();
    char* object = (char*)Field_GetSharedSubscreenInstance(*(void**)(resources + 0x3708));
    GameObject* actor = GameState_GetObjectWithFlag100(game, *(int*)(object + 0x4fc));
    if (!actor) return;
    short* values = (short*)GameObject_GetLinkedStatsOrNull((char*)actor);
    for (int i = 0; i < 8; i++) {
        TextEntry_ReleaseGlyphRunReferences((void*)renderer, p + 0x3e84 + i * 128, 64);
        for (int j = 0; j < 64; j++)
            *(unsigned short*)((p + (i << 7) + (j << 1)) + 0x3e84) = 65535;
        *(unsigned char*)((p + i) + 0x4284) = 0;
    }
    for (int i = 0; i < 8; i++) {
        int id = values[EquipmentMenuCacheEquippedItemNames_UnknownRoleInitializedBytes[i]];
        char* record = (char*)ZoneState2754_FindPrimaryRecordByKey(*(ZoneState2754**)(p + 0xdf4), id);
        char output[128];
        __clear(output, 128);
        if (record) {
            char input[128];
            __clear(input, 128);
            Text_FormatAndConditionallyUppercaseOutput(*(const char**)(record + 4), input, 0);
            TextMarkup_ExpandAndWrapText((void*)renderer, 0, input, output, 88, 0, 0);
        } else if (id <= 0) {
            void* text = ResourceStringTable_GetTextByKey(p + 0xdf8, (void*)0x2ee0);
            TextMarkup_ExpandAndWrapText((void*)renderer, 0, text, output, 88, 0, 0);
        } else {
            void* text = ResourceStringTable_GetTextByKey(p + 0xdf8, (void*)0x32c7);
            TextMarkup_ExpandAndWrapText((void*)renderer, 0, text, output, 88, 0, 0);
        }
        if (String_FindFirstSubstring(output, EquipmentMenuCacheEquippedItemNames_UnknownRoleInitializedBytes_Variant2))
            *(unsigned char*)((p + i) + 0x4284) = 1;
        TextLayout_ConvertMarkupToCachedGlyphIndices((void*)renderer, output, p + 0x3e84 + i * 128, 0);
        TextWindow_RenderAndTransferDisplayBuffers((void*)renderer, 0);
        p[0x3e04] = 2;
    }
}
