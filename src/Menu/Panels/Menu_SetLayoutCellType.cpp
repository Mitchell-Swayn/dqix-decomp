#include <globaldefs.h>
ARM
extern "C" unsigned char *Menu_ResolveFirstLayoutCellForGroup(void *, void *);
// Original: arm9/ov023 @ 0x021E29B8; symbol: Record_SetByte2ForResolvedKey; size: 0x18.
// Looks up the record using the first two arguments and, if found, stores the third argument at byte offset +2.
extern "C" void Menu_SetLayoutCellType(void *a, void *b, unsigned char value) {
    unsigned char *result = Menu_ResolveFirstLayoutCellForGroup(a, b);
    if (result)
        result[2] = value;
}
