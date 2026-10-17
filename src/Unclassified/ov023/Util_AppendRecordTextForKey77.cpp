#include <globaldefs.h>
ARM
extern "C" unsigned int FindRecordValueByKeyOrZero(void *record, int key);
extern "C" int AppendFormatText(char *p, const char *text);
// Original: arm9/ov023 @ 0x021E8EF8; symbol: func_ov023_021e8ef8; size: 0x30.
extern "C" void Util_AppendRecordTextForKey77(void *object) {
    void *record = *(void **)((char *)object + 0x5f4);
    if (!record)
        return;
    char *buffer = *(char **)((char *)object + 0x5d8);
    const char *text = (const char *)FindRecordValueByKeyOrZero(record, 0x77);
    AppendFormatText(buffer, text);
}
