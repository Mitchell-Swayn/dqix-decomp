#include <globaldefs.h>
ARM
extern "C" int Random_ScaleIntegerByRandFraction(int);
extern "C" void* _Z11GetBTRandomv();
struct E{unsigned short key;char pad[74];};
extern "C" E *Script_FindWeightedGroupById(E *p,unsigned int key);
struct Entry { unsigned key : 12; unsigned flags : 20; unsigned short value : 8; unsigned short chance : 8; unsigned short extra; };
struct Record { unsigned short key; unsigned char count, pad; Entry entries[9]; };
// Original: arm9/ov017 @ 0x021B8A34; symbol: func_ov017_021b8a34; size: 0x88.
extern "C" int Util_RollKeyedRecordValue(E *records, unsigned key, unsigned entryKey) {
    _Z11GetBTRandomv();
    Record *record = (Record*)Script_FindWeightedGroupById(records, key);
    if (record) {
        for (int i = 0; i < record->count; i++) {
            if (entryKey == record->entries[i].key) {
                if (Random_ScaleIntegerByRandFraction(100) < record->entries[i].chance)
                    return record->entries[i].value;
                break;
            }
        }
    }
    return -1;
}
