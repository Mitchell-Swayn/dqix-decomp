#include <globaldefs.h>
ARM
extern "C" char *Menu_FindCanvasNodeByKey(void *, int);
extern "C" unsigned MenuRecord_GetType(void *);
// Original: arm9/ov004 @ 0x0215E49C; symbol: Unclassified_WriteField38WhenRecordKindEight; size: 0x24.
// Looks up the keyed record; when its halfword at +4 equals 8, writes the supplied halfword at +0x38.
extern "C" void Menu_SetTextEntryMessageId(void *p, int key, unsigned short value) {
    char *record = Menu_FindCanvasNodeByKey(p, key);
    if (record && MenuRecord_GetType(record) == 8)
        *(unsigned short *)(record + 0x38) = value;
}
