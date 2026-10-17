#include <globaldefs.h>
ARM
extern "C" void* ReadGlobalValueAt020FB3F0();
extern "C" void* ReadGlobalAt020FDD44();
struct E { unsigned short id; unsigned short unused : 4; unsigned short value : 12; };
extern "C" E *FindRecordAmongFourByNonnegativeKey(E *p,int key);
// Original: arm9/ov017 @ 0x021CF4E8; symbol: func_ov017_021cf4e8; size: 0xAC.
extern "C" void GameState_ApplyIndexedStatusAndRecord(void *unused, unsigned char *input, char *self, char *context) {
    int index = input[4];
    int valid;
    if ((unsigned)index <= 3) valid = 1; else valid = 0;
    if (valid) {
        *(unsigned char *)(self + index + 0x7f76) = input[5];
        if (input[5] == 2) {
            unsigned short *destination = (unsigned short *)(context + 0x44b4);
            unsigned short *zone = (unsigned short *)ReadGlobalValueAt020FB3F0();
            E *records = (E *)ReadGlobalAt020FDD44();
            E *record = FindRecordAmongFourByNonnegativeKey(records, *zone);
            if (record) {
                destination[0] = *zone;
                destination[1] = record->value;
            }
        }
    } else *(unsigned char *)(self + index + 0x7f76) = 5;
    *(unsigned char *)(self + 0x7f7a) |= 1 << input[4];
}
