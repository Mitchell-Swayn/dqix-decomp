#include <globaldefs.h>
ARM
struct Record {
    char pad[3]; unsigned char low : 4; unsigned char high : 4;
    char pad4[8]; unsigned value;
    unsigned char option : 4; unsigned char flag4 : 1; unsigned char flag5 : 1; unsigned char flag6 : 1; unsigned char reserved : 1;
};
extern "C" Record *Menu_ResolveFirstLayoutCellForGroup(void*, int);
// Original: arm9/ov023 @ 0x021E24B0; symbol: func_ov023_021e24b0; size: 0xA0.
extern "C" void Menu_ConfigureLayoutCellRendering(void *self, int index, unsigned value, unsigned char low, unsigned char high, unsigned char flag4, unsigned char option, unsigned char flag5, unsigned char flag6) {
    Record *record = Menu_ResolveFirstLayoutCellForGroup(self, index);
    if (!record) return;
    record->value = value;
    record->low = low;
    record->high = high;
    record->flag4 = flag4;
    record->option = option;
    record->flag5 = flag5;
    record->flag6 = flag6;
}
