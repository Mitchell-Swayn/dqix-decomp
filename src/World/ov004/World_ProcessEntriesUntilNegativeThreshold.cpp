#include <globaldefs.h>
ARM
struct ThresholdTable { int values[3]; };
extern "C" void func_ov004_02155a3c();
extern "C" void World_ApplyStateValueToMatchingType6Entry(void*, int);
extern "C" ThresholdTable data_ov004_0216fae0;
// Original: arm9/ov004 @ 0x02155B6C; symbol: func_ov004_02155b6c; size: 0x50.
extern "C" int World_ProcessEntriesUntilNegativeThreshold(void* object) {
    func_ov004_02155a3c();
    ThresholdTable local = data_ov004_0216fae0;
    int index = 0;
    while (local.values[index] >= 0) {
        World_ApplyStateValueToMatchingType6Entry(object, local.values[index]);
        ++index;
    }
    return 0;
}
