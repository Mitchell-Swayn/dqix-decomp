#include <globaldefs.h>
ARM

extern "C" void func_0206e164(void *, int, unsigned, unsigned);

// Original: arm9/main @ 0x0206E218; symbol: func_0206e218; size: 0x48.
extern "C" void Object_SetBoundedIndexedModeFlag(void *object, int index) {
    if (index >= 0xCC || index < 0) {
        return;
    }
    int remainder = index % 2;
    int adjustedIndex = index + (int)((unsigned int)index >> 31);
    unsigned char *flag = (unsigned char *)object + 0x2CC + (adjustedIndex >> 1);
    *flag |= remainder ? 0x40 : 4;
    func_0206e164(object, index, 1, (unsigned)adjustedIndex);
}
