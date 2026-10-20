#include <globaldefs.h>
extern "C" void* memset(void*, int, unsigned int);
struct FlagStateRow { unsigned char high, middle, low; unsigned char firstFlags[4]; unsigned char reserved7[9]; unsigned char secondFlags[4]; unsigned char reserved20[8]; };
struct FlagStateOwner { FlagStateRow active[5]; unsigned char reserved8c[0x2a8]; FlagStateRow staged[5]; unsigned char globalFlags[66]; unsigned char reserved402[2]; int dirty; int stagedDirty; unsigned char packedFlags[1]; };
// Original: arm9/main @ 0x0206E748; symbol: func_0206e748; size: 0x334.
// Applies global, staged-row, packed-state or nibble flag changes and sets their dirty markers.
extern "C" ARM void GameState_ApplyEncodedFlagUpdate(FlagStateOwner* owner, int kind, unsigned int row, int bit, int value)
{
    if (kind == 0) {
        unsigned int index = (unsigned int)bit >> 3;
        unsigned char mask = 1 << (bit % 8);
        if (index < 66) {
            if (value) { if (owner->globalFlags[index] & mask) return; owner->globalFlags[index] |= mask; }
            else { if (!(owner->globalFlags[index] & mask)) return; owner->globalFlags[index] &= ~mask; }
        }
    } else if (kind == 1) {
        unsigned int index = ((unsigned int)bit >> 3) + 64;
        unsigned char mask = 1 << (bit % 8);
        if (index < 66) {
            if (value) owner->globalFlags[index] |= mask;
            else owner->globalFlags[index] &= ~mask;
        }
        owner->stagedDirty = 1;
        return;
    } else if (kind == 2) {
        if (row < 5) {
            unsigned char high = (value >> 10) & 31;
            unsigned char middle = (value >> 5) & 31;
            unsigned char low = value & 31;
            if (owner->staged[row].high != high) {
                memset(owner->staged[row].firstFlags, 0, 4);
                memset(owner->staged[row].secondFlags, 0, 4);
            } else if (owner->staged[row].middle != middle) memset(owner->staged[row].secondFlags, 0, 4);
            owner->staged[row].high = high;
            owner->staged[row].middle = middle;
            owner->staged[row].low = low;
            if (value & 0x8000) {
                owner->active[row].high = high;
                owner->active[row].middle = middle;
                owner->active[row].low = low;
            }
        }
    } else if (kind == 3) {
        if (row < 5) {
            unsigned int index = (unsigned int)bit >> 3;
            unsigned char mask = 1 << (bit % 8);
            if (value) { if (owner->staged[row].firstFlags[index] & mask) return; owner->staged[row].firstFlags[index] |= mask; }
            else { if (!(owner->staged[row].firstFlags[index] & mask)) return; owner->staged[row].firstFlags[index] &= ~mask; }
            owner->stagedDirty = 1;
            return;
        }
    } else if (kind == 5) {
        if (row < 5) {
            unsigned int index = (unsigned int)bit >> 3;
            unsigned char mask = 1 << (bit % 8);
            if (value) { if (owner->staged[row].secondFlags[index] & mask) return; owner->staged[row].secondFlags[index] |= mask; }
            else { if (!(owner->staged[row].secondFlags[index] & mask)) return; owner->staged[row].secondFlags[index] &= ~mask; }
            owner->stagedDirty = 1;
            return;
        }
    } else if (kind == 7) {
        if ((unsigned int)bit >= 174) {
            unsigned char relative = bit - 174;
            unsigned char index = relative / 2;
            if ((unsigned char)(relative % 2)) {
                unsigned char upper = owner->packedFlags[index] >> 4;
                upper = (upper & 12) | value;
                // Preserve the two byte updates: MW folds the first store into the final store.
                owner->packedFlags[index] &= 15;
                owner->packedFlags[index] |= upper << 4;
            } else {
                unsigned char lower = owner->packedFlags[index] & 15;
                lower = (lower & 12) | value;
                owner->packedFlags[index] &= 0xf0;
                owner->packedFlags[index] |= lower;
            }
        }
    }
    owner->dirty = 1;
}
