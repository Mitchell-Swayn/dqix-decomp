#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
#pragma force_active on
extern "C" unsigned char TreasureMapCollection_ReadMapCount();
extern "C" int TextMarkup_AppendFrameTag(char*, int, int, int, int, int);
extern "C" int TextMarkup_AppendCursorTag(char*, int);
extern "C" void* ResourceStringTable_GetTextByKey(void*, void*);
extern "C" int AppendFormattedNumberAndText(char*, const char*, int);
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*, int, const char*);
extern "C" int Text_AppendFormatString(char*, const char*);
// Original: arm9/ov002 @ 0x0215C52C; symbol: func_ov002_0215c52c; size: 0xe8.
// Builds inventory-category choices, omitting the map category when no treasure maps are owned.
extern "C" void PartyMenu_AppendInventoryCategoryOptions(void* owner, void* buffer, int styled) {
    char* self = (char*)owner;
    char* output = (char*)buffer;
    if (!output) return;
    short selected = *(short*)(self + 0x1be4);
    short key = 1002;
    int count = 3;
    GameState::GetInstance();
    if (!TreasureMapCollection_ReadMapCount()) count = 2;
    if (styled) TextMarkup_AppendFrameTag(output, selected, 8, 5, 5, 5);
    TextMarkup_AppendCursorTag(output, selected);
    const char* title = (const char*)ResourceStringTable_GetTextByKey(self + 32, (void*)1000);
    AppendFormattedNumberAndText(output, title, 24);
    for (int i = 0; i < count; ++i) {
        const char* text = (const char*)ResourceStringTable_GetTextByKey(self + 32, (void*)(int)key++);
        Text_AppendFormattedIntegerAndStringFragment(output, i, text);
        if (i != count - 1) Text_AppendFormatString(output, *(const char**)(self + 0x1bdc));
    }
}
