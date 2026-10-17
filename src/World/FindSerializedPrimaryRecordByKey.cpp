#include "World/Zone3DEmbeddedState.h"
// Original: arm9/main @ 0x020DEDD0; symbol: func_020dedd0; size: 0x88.
extern "C" void* FindSerializedPrimaryRecordByKey(ZoneState2754* state, int key)
{
    if (key < 0) return 0;
    if (state->unknown_14) return state->data.FindPrimaryRecord(key, GetSerializedRecordKey);
    int i;
    char* record = state->data.records;
    if (!record || (unsigned int)GetSerializedRecordKey == 0) record = 0;
    else {
        int count = state->data.primaryCount;
        if (count == 0) record = 0;
        else {
            i = 0;
            while (i < count) {
                if (key == GetSerializedRecordKey(record)) goto done;
                ++i;
                record += 32;
            }
            record = 0;
        }
    }
done:
    return record;
}
