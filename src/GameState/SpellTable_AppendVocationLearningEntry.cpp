#include <globaldefs.h>

struct PointEntry {
    unsigned short x;
    unsigned short y;
};

// Thirteen point lists of twenty entries (0x50 bytes each), then per-list counts.
struct PointListBlock {
    char pad0[0x10c];
    PointEntry lists[13][20];
    int counts[13];
};

struct PointListOwner {
    PointListBlock* block;
};

// Original: arm9/main @ 0x0209A97C; symbol: func_0209a97c; size: 0x60.
extern "C" void SpellTable_AppendVocationLearningEntry(PointListOwner* owner, int list, const PointEntry* entry) {
    PointListBlock* block = owner->block;
    if (block == 0) {
        return;
    }
    int count = block->counts[list];
    if (count >= 20) {
        return;
    }
    block->counts[list]++;
    PointEntry* destination = owner->block->lists[list] + count;
    destination->x = entry->x;
    destination->y = entry->y;
}
