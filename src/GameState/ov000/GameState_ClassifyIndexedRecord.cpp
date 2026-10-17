#include <globaldefs.h>
ARM
extern "C" char *FindFourSlotRecordByIndex(char *records, int index);
extern "C" int ClassifyRatioAtThresholds(void *record);
// Original: arm9/ov000 @ 0x02174E34; symbol: func_ov000_02174e34; size: 0x1C.
extern "C" int GameState_ClassifyIndexedRecord(char *records, int index) {
    char *record = FindFourSlotRecordByIndex(records, index);
    return record ? ClassifyRatioAtThresholds(record) : -1;
}
