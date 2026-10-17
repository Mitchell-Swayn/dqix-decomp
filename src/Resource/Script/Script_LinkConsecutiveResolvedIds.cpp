#include <globaldefs.h>
#include "Resource/Script.h"

extern "C" void* data_020fdd30;
extern "C" {
void* FindSixteenByteEntryByKey(void* manager, int id);
void Object_AppendPairWithinCapacity(void* manager, void** pair);
}

// Looks up the objects named by the script parameters and links each with the previous one.
// Original: arm9/main @ 0x02027E44; symbol: func_02027e44; size: 0xA8.
extern "C" ARM int Script_LinkConsecutiveResolvedIds(Script::Parameter* params, int count) {
    void* pair[2];
    pair[1] = 0;
    pair[0] = 0;

    int id = (params++)->ToInt();
    count--;
    pair[0] = FindSixteenByteEntryByKey(data_020fdd30, id);
    while (count >= 0) {
        id = (params++)->ToInt();
        count--;
        pair[1] = FindSixteenByteEntryByKey(data_020fdd30, id);
        if (pair[0] && pair[1]) Object_AppendPairWithinCapacity(data_020fdd30, pair);
        if (pair[1]) pair[0] = pair[1];
    }
    return 1;
}
