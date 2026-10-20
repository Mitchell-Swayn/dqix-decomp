#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0203E6C8; symbol: System_InsertMaskedValueIntoSortedHalfwordTable; size: 0xEC.
extern "C" int System_InsertMaskedValueIntoSortedHalfwordTable(void* table, unsigned flags) {
    char* object = (char*)table;
    if ((flags & 0x8000) == 0) return 0;
    unsigned short key = (unsigned short)(flags & *(unsigned short*)(object + 0x0a));
    unsigned base = 0;
    int step = *(unsigned short*)(object + 8);
    int decision = 0;
    while (step > 0) {
        step >>= 1;
        unsigned index = base + (unsigned)step;
        unsigned short count = *(unsigned short*)(object + 6);
        if (index < count) {
            unsigned short value = ((unsigned short*)*(unsigned**)object)[index];
            if (key == value) decision = 0;
            else if (key < value) decision = -1;
            else decision = 1;
            if (decision == 0) return (int)index;
            if (decision >= 0) base += (unsigned)step;
        }
    }
    unsigned short count = *(unsigned short*)(object + 6);
    if (count >= *(unsigned short*)(object + 4)) return -1;
    unsigned short* cursor = ((unsigned short*)*(unsigned**)object) + count;
    unsigned i = count;
    while (i > base + 1) {
        *cursor = cursor[-1];
        --cursor;
        --i;
    }
    *cursor = key;
    *(unsigned short*)(object + 6) = *(unsigned short*)(object + 6) + 1;
    volatile unsigned short* step_field = (volatile unsigned short*)(object + 8);
    if (*step_field < *(unsigned short*)(object + 6))
        *step_field = *step_field << 1;
    return (int)(base + 1);
}
