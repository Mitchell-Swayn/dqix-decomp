#include <globaldefs.h>
struct KeyedRecord212 { unsigned char unknown[0xd0]; unsigned int key; };
struct SixteenRecordOwner { unsigned char header[8]; KeyedRecord212 records[16]; };
// Original: arm9/main @ 0x02058680; symbol: func_02058680; size: 0x84.
// Counts matching record keys, or collects at most capacity record pointers.
extern "C" ARM int CollectRecordPointersByKey(SixteenRecordOwner* owner, unsigned int key, KeyedRecord212** output, int capacity)
{
    int i1;
    char* records;
    int count;
    int i2;
    count = 0;
    if (capacity == 0) {
        for (i1 = 0; i1 < 16; ++i1) if (owner->records[i1].key == key) ++count;
    } else {
        records = (char*)owner;
        records += 8;
        for (i2 = 0; i2 < 16; ++i2) {
            if (owner->records[i2].key == key) {
                if (count < capacity) { output[count] = (KeyedRecord212*)(records + i2 * 0xd4); ++count; }
            }
        }
    }
    return count;
}
