#include "CountMenu.h"

extern "C" CountMenuEntry* func_ov004_02153944(CountMenuContext* menu, int id)
{
    CountMenuEntry* entry = func_ov023_021f6880(func_ov011_021849c8(menu), id);
    if (!entry)
        return 0;
    if (func_ov023_021f6f10(entry) != 6)
        entry = 0;
    return entry;
}

// Decode UI selection IDs into the signed keys used by the count cache.
// The -1 sentinel survives absent entries and unrecognized selection IDs.
extern "C" void func_ov004_02153978(CountMenuContext* menu, short* category,
                                    short* primaryKey, short* secondaryKey)
{
    *category = *primaryKey = *secondaryKey = -1;
    CountMenuEntry* entry = func_ov023_021f6590(menu, 5);
    if (!entry)
        return;
    switch (func_ov023_021f6f08(entry)) {
    case 26:
        *category = 0;
        break;
    case 27:
        *primaryKey = 0;
        entry = func_ov023_021f6590(menu, 42);
        if (!entry)
            return;
        switch (func_ov023_021f6f08(entry)) {
        case 26: *secondaryKey = 0; break;
        case 32: *secondaryKey = 1; break;
        case 27: *secondaryKey = 2; break;
        case 33: *secondaryKey = 3; break;
        case 28: *secondaryKey = 4; break;
        case 34: *secondaryKey = 5; break;
        case 29: *secondaryKey = 6; break;
        case 35: *secondaryKey = 7; break;
        case 30: *secondaryKey = 8; break;
        case 36: *secondaryKey = 9; break;
        case 31: *secondaryKey = 10; break;
        case 37: *secondaryKey = 11; break;
        default: break;
        }
        break;
    case 28:
        entry = func_ov023_021f6590(menu, 43);
        if (!entry)
            return;
        switch (func_ov023_021f6f08(entry)) {
        case 26: *primaryKey = 1; break;
        case 27: *primaryKey = 2; break;
        case 28: *primaryKey = 3; break;
        case 29: *primaryKey = 4; break;
        case 30: *primaryKey = 5; break;
        case 31: *primaryKey = 6; break;
        default: break;
        }
        break;
    case 29:
        *category = 3;
        *primaryKey = 7;
        break;
    }
}
