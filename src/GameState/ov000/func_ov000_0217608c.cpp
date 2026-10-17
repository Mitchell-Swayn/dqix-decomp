#include <globaldefs.h>
ARM
extern "C" void* FindFourSlotRecordByIndex(void*, int);
extern "C" unsigned int ReadByteAtOffset445(void*);
// Original: arm9/ov000 @ 0x0217608C; symbol: func_ov000_0217608c; size: 0x48.
extern "C" int func_ov000_0217608c(void* records) {
    int count = 0;
    for (int i = 0; i < 4; ++i) {
        void* record = FindFourSlotRecordByIndex(records, i);
        if (record && ReadByteAtOffset445(record)) ++count;
    }
    return count;
}
