#include <globaldefs.h>
ARM
#pragma force_active on
// Retain the original entry when callers remain in weak-reference fallback objects.
// The original lookup forwards its key in r1 and returns the child pointer in r0.
extern "C" void* TileGrid_FindSelectedChildRecord(void*, unsigned);
extern "C" unsigned short MenuRecord_GetKey(const void*);
// Original: arm9/ov004 @ 0x02153978; symbol: func_ov004_02153978; size: 0x1f4.
// Maps the selected catalogue category and subcategory grid cells to three signed filters.
extern "C" void Menu_GetCatalogueCategoryFilters(void* self, short* primary, short* secondary, short* subtype)
{
    *primary = *secondary = *subtype = -1;
    void* selected = TileGrid_FindSelectedChildRecord(self, 5);
    if (!selected) return;
    switch (MenuRecord_GetKey(selected)) {
    case 0x1a:
        *primary = 0;
        return;
    case 0x1b:
        *secondary = 0;
        selected = TileGrid_FindSelectedChildRecord(self, 0x2a);
        if (!selected) return;
        switch (MenuRecord_GetKey(selected)) {
        case 0x1a: *subtype = 0; return;
        case 0x20: *subtype = 1; return;
        case 0x1b: *subtype = 2; return;
        case 0x21: *subtype = 3; return;
        case 0x1c: *subtype = 4; return;
        case 0x22: *subtype = 5; return;
        case 0x1d: *subtype = 6; return;
        case 0x23: *subtype = 7; return;
        case 0x1e: *subtype = 8; return;
        case 0x24: *subtype = 9; return;
        case 0x1f: *subtype = 10; return;
        case 0x25: *subtype = 11; return;
        }
        break;
    case 0x1c:
        selected = TileGrid_FindSelectedChildRecord(self, 0x2b);
        if (!selected) return;
        switch (MenuRecord_GetKey(selected)) {
        case 0x1a: *secondary = 1; return;
        case 0x1b: *secondary = 2; return;
        case 0x1c: *secondary = 3; return;
        case 0x1d: *secondary = 4; return;
        case 0x1e: *secondary = 5; return;
        case 0x1f: *secondary = 6; return;
        }
        break;
    case 0x1d:
        *primary = 3;
        *secondary = 7;
        return;
    }
}
