#include <globaldefs.h>
ARM
#include <System/Matrix.h>
struct Object;
extern "C" void ReadFirstAvailableVectorOrZero(Vector3i*,Object*);
struct Entry { unsigned type, a,b; char *object; };
// Original: arm9/ov001 @ 0x02164418; symbol: func_ov001_02164418; size: 0xB0.
extern "C" int Util_ReadTypedTableEntryVector(Entry *table, int index, Vector3i *out) {
    if (index < 0 || index >= 32) return 0;
    Entry *entry = table + index;
    switch (entry->type) {
    case 0: case 1: case 4: case 5:
        if (!entry->object) return 0;
        *out = *(Vector3i*)(entry->object + 0x44);
        return 1;
    case 2: case 6: {
        if (!entry->object) return 0;
        Vector3i value;
        ReadFirstAvailableVectorOrZero(&value, (Object*)entry->object);
        *out = value;
        return 1;
    }
    default: return 0;
    }
}
