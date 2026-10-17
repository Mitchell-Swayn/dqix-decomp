#include <globaldefs.h>
ARM
extern "C" unsigned int Object_GetSelectedRecordWhenBuffersEnabled(char *p);
extern "C" bool TestField9CEqualsThree(int self);
extern "C" void Object_SetWordAtOffset30(int object, unsigned int value);
extern "C" unsigned int Object_UpdateDisplayRecordsAndPendingSelection(unsigned char *self, unsigned int value);
// Original: arm9/ov003 @ 0x021694B8; symbol: func_ov003_021694b8; size: 0x54.
extern "C" void Object_UpdateSelectionAndDisplay(unsigned char *base, unsigned int value) {
    unsigned int record = Object_GetSelectedRecordWhenBuffersEnabled((char *)(base + 0xE4));
    if (record != 0 && TestField9CEqualsThree((int)record) && (*(unsigned char *)(record + 0xC5) & 2) == 0) {
        Object_SetWordAtOffset30((int)(base + 0xE8), 0xFFFFFFFF);
    }
    base[0x4EA] = (unsigned char)Object_UpdateDisplayRecordsAndPendingSelection(base + 0xE4, value);
}
