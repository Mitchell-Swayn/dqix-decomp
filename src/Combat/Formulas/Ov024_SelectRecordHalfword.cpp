#include <globaldefs.h>
extern "C" unsigned short Combat_SelectMessageForPartyOrMonster(int, int, int);
struct HighField { unsigned pad:20; unsigned high:10; unsigned rest:2; };
struct LowField { unsigned low:10; unsigned pad:22; };
// Original: arm9/ov024 @ 0x021E9B24; symbol: func_ov024_021e9b24; size: 0x50.
extern "C" unsigned short Ov024_SelectRecordHalfword(void *unused, int index, char *record, int useFirstPair) {
    if (useFirstPair) {
        unsigned int value = *(unsigned int *)(record + 0x24);
        return Combat_SelectMessageForPartyOrMonster(index, (value << 12) >> 22, (value << 2) >> 22);
    }
    int yes = ((HighField *)(record + 0x20))->high;
    int no = ((LowField *)(record + 0x24))->low;
    return Combat_SelectMessageForPartyOrMonster(index, yes, no);
}
