#include <globaldefs.h>
ARM
struct Object3D;
struct Entry { unsigned state; unsigned char pad[8]; Object3D* object; };
extern "C" void _ZN8Object3D9SetRadiusEi(Object3D*, int);
// Original: arm9/ov001 @ 0x021649D4; symbol: func_ov001_021649d4; size: 0x54.
extern "C" int GameState_SetRadiusForActiveEntry(Entry* table, int index, int radius) {
    if (index < 0 || index >= 0x20) return 0;
    Entry* entry = table + index;
    if (entry->state == 1) {
        if (!entry->object) return 0;
        _ZN8Object3D9SetRadiusEi(entry->object, radius);
        return 1;
    }
    return 0;
}
