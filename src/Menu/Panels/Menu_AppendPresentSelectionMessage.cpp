#include <globaldefs.h>
ARM
extern "C" unsigned int MessageTextTable_FindTextById(void *record, int key);
extern "C" int Text_AppendFormatString(char *p, const char *text);
// Original: arm9/ov023 @ 0x021E8EF8; symbol: func_ov023_021e8ef8; size: 0x30.
extern "C" void Menu_AppendPresentSelectionMessage(void *object) {
    void *record = *(void **)((char *)object + 0x5f4);
    if (!record)
        return;
    char *buffer = *(char **)((char *)object + 0x5d8);
    const char *text = (const char *)MessageTextTable_FindTextById(record, 0x77);
    Text_AppendFormatString(buffer, text);
}
