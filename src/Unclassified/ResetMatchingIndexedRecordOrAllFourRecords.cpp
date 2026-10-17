#include <globaldefs.h>
extern "C" unsigned char data_020fdc60[];
extern "C" void ResetModeDependentRecordValueAndCounter(void* record);
// Original: arm9/main @ 0x02027288; symbol: func_02027288; size: 0x7C.
extern "C" void ResetMatchingIndexedRecordOrAllFourRecords(unsigned char* state, unsigned int index)
{
    if (static_cast<int>(index) < 0) {
        for (int i = 0; i < 4; ++i) {
            ResetModeDependentRecordValueAndCounter(data_020fdc60 + i * 0x14);
        }
        return;
    }
    if (static_cast<int>(index) >= 4) return;
    for (int i = 0; i < 4; ++i) {
        unsigned char* entry = state + i;
        if (index == entry[0x758]) {
            ResetModeDependentRecordValueAndCounter(data_020fdc60 + i * 0x14);
            return;
        }
    }
}
