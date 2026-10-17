#include <globaldefs.h>
ARM
extern "C" int ReadHalfwordAtOffsetC(void*);
struct Entry { unsigned words[4]; };
struct Table { unsigned count : 12; unsigned flags : 20; Entry *records; };
// Original: arm9/main @ 0x020E52A0; symbol: func_020e52a0; size: 0x94.
extern "C" void *Util_FindSixteenByteRecordByHalfwordKey(Table *table, int key) {
    if (!table) return 0;
    Entry *records = table->records;
    int mid, high, low;
    Entry *result;
    if (!records || (unsigned)ReadHalfwordAtOffsetC == 0) { result=0; goto done; }
    {
        int count = table->count;
        if (!count) { result=0; goto done; }
        high = count - 1;
        low = 0;
        while (low <= high) {
            mid = low + ((high - low + 1) >> 1);
            result = &records[mid];
            int found = ReadHalfwordAtOffsetC(result);
            if (found == key) goto done;
            if (found > key) high = mid - 1;
            else low = mid + 1;
        }
        result = 0;
    }
    done:
    if (!result) result = 0;
    return result;
}
