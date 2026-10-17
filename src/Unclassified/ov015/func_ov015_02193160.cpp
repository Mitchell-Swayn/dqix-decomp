#include <globaldefs.h>
ARM
struct RecordArray;
struct Record;
extern "C" Record *func_ov015_0218bae8(RecordArray *, int);

// Original: arm9/ov015 @ 0x02193160; symbol: func_ov015_02193160; size: 0x54.
extern "C" Record *func_ov015_02193160(void *object, unsigned char value, int *index) {
    int current = *index;
    while (current < *(int *)((unsigned char *)object + 0x44)) {
        Record *record = func_ov015_0218bae8((RecordArray *)((unsigned char *)object + 0x3c), current);
        if (record == 0) break;
        if (value == *((unsigned char *)record + 0xa)) {
            *index = current;
            return record;
        }
        ++current;
    }
    return 0;
}
