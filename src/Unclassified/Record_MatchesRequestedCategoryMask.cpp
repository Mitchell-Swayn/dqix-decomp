#include <globaldefs.h>
ARM
#include <std_library_functions.h>
struct HalfwordCategory { unsigned short ignored:2; unsigned short value:4; unsigned short rest:10; };
struct ByteCategory { unsigned char value:4; unsigned char rest:4; };
struct FilterRecord { unsigned flags0; unsigned unused4; unsigned flags1; unsigned char unusedC[12]; HalfwordCategory category[2]; ByteCategory secondary[2]; unsigned char unused1E[10]; unsigned copyValues[2]; };
// Original: arm9/main @ 0x0209E1CC; symbol: func_0209e1cc; size: 0x210.
// Tests selected record category fields against a bit mask; mode selects one of two field groups.
extern "C" int Record_MatchesRequestedCategoryMask(void* context, const FilterRecord* record, int mode, int mask)
{
    // Union storage preserves the original compiler register allocation for flags.
    union { unsigned word; } flags;
    unsigned category, secondary, copied;
    if (mode == 0) {
        flags.word = record->flags0;
        category = record->category[0].value;
        secondary = record->secondary[0].value;
        memcpy(&copied, &record->copyValues[0], 4);
    } else {
        flags.word = record->flags1;
        category = record->category[1].value;
        secondary = record->secondary[1].value;
        memcpy(&copied, &record->copyValues[1], 4);
    }
    if (mask & 0x1) { if (flags.word & 0x80000) { if (category == 2) return 1; } }
    if (mask & 0x2) { if (flags.word & 0x80000) { if (category == 3) return 1; } }
    if (mask & 0x4) { if (flags.word & 0x80000) { if (category == 5) return 1; } }
    if (mask & 0x8) { if (flags.word & 0x80000) { if (category == 4) return 1; } }
    if (mask & 0x10) { if (flags.word & 0x80000) { if (category == 7) return 1; } }
    if (mask & 0x20) { if (flags.word & 0x80000) { if (category == 6) return 1; } }
    if (mask & 0x40) { if (flags.word & 0x80000) { if (category == 8) return 1; } }
    if (mask & 0x80) { if (flags.word & 0x80000) { if (category == 10) return 1; } }
    if (mask & 0x100) { if (flags.word & 0x80000) { if (category == 9) return 1; } }
    if (mask & 0x200) { if (flags.word & 0x80000) { if (category == 1) return 1; } }
    if (mask & 0x400) { if (secondary == 1) return 1; }
    if (mask & 0x800) { if (secondary == 2) return 1; }
    if (mask & 0x1000) { if (secondary == 4) return 1; }
    if (mask & 0x2000) { if (secondary == 5) return 1; }
    if (mask & 0x4000) { if (secondary == 6) return 1; }
    if (mask & 0x8000) { if (secondary == 7) return 1; }
    if (mask & 0x10000) { if (secondary == 8) return 1; }
    return 0;
}
