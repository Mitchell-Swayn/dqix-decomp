#include <globaldefs.h>
ARM
#pragma force_active on
// Retain the original entry when callers remain in weak-reference fallback objects.
// The original lookup forwards its key in r1 and returns the child pointer in r0.
extern "C" void* TileGrid_FindSelectedChildRecord(void*, unsigned);
extern "C" unsigned short MenuRecord_GetKey(const void*);
// Original: arm9/ov004 @ 0x0215513c; symbol: func_ov004_0215513c; size: 0x6c.
// Maps the selected alternate category to primary or secondary catalogue filters.
extern "C" void Menu_GetAlternateCatalogueCategoryFilters(void* self, short* primary, short* secondary, short* subtype)
{
    *primary = *secondary = *subtype = -1;
    void* selected = TileGrid_FindSelectedChildRecord(self, 5);
    if (!selected) return;
    switch (MenuRecord_GetKey(selected)) {
    case 0x1a: *primary = 0; break;
    case 0x1b: *secondary = 8; break;
    case 0x1c: *secondary = 9; break;
    }
}
