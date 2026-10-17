#include <globaldefs.h>
struct Vector { int x,y,z; };
struct Entry { unsigned char id; unsigned char pad[3]; short x,y,z; unsigned char tail[6]; };
struct Table { unsigned char pad[2]; unsigned char count; unsigned char pad3; Entry* entries; };
extern "C" int Vector3fix_Distance(const Vector*, const Vector*);
// Original: arm9/main @ 0x02028638; symbol: func_02028638; size: 0xC4.
extern "C" ARM int Object_FindClosestFixedPointPositionEntryId(Table* table, const Vector* position) {
    if (!table->count) return 0;
    Entry* entries = table->entries;
    Vector first;
    first.x = entries[0].x * 4096; first.y = entries[0].y * 4096; first.z = entries[0].z * 4096;
    int result = 0;
    int best = Vector3fix_Distance(position, &first);
    for (int i=1;i<table->count;i++) {
        Vector current;
        current.x=entries[i].x*4096; current.y=entries[i].y*4096; current.z=entries[i].z*4096;
        int distance=Vector3fix_Distance(position,&current);
        if(distance<best) { result=entries[i].id; best=distance; }
    }
    return result;
}
