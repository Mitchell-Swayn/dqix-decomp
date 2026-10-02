#include "World/Zone3DEmbeddedState.h"

void* ZoneState2754::FindPrimaryRecord(int key, int (*getKey)(const void*))
{
    char* records = data.records;
    if (!records || !getKey) return 0;
    int count = data.primaryCount;
    if (count == 0) return 0;
    int low;
    int high = count - 1;
    low = 0;
    while (low <= high)
    {
        int middle = low + ((high - low + 1) >> 1);
        char* record = records + middle * 32;
        int value = getKey(record);
        if (value == key) return record;
        if (value > key) high = middle - 1;
        else low = middle + 1;
    }
    return 0;
}
