#include <globaldefs.h>
ARM
#pragma force_active on
// Retain original presentation entries while some callers remain in weak-reference fallback objects.
extern "C" void BattleGrid_GetNeighborCells(unsigned char*, int*);
struct NeighborCells { unsigned char cells[6]; };
// Original: arm9/ov025 @ 0x021e12f8; symbol: func_ov025_021e12f8; size: 0xe8.
// Recursively paints a six-neighbor footprint after its clearance delay, skipping blocked grid cells.
extern "C" void BattleGrid_PaintFootprintAfterClearance(unsigned char* grid, int cell, unsigned char value, unsigned char limit, unsigned char remaining, unsigned char depth)
{
    if (limit == depth) return;
    if (remaining) --remaining;
    if (!remaining) ++depth;
    struct Local { int cell; unsigned char neighbors[6], copied[6]; } local;
    local.cell = cell;
    BattleGrid_GetNeighborCells(local.neighbors, &local.cell);
    *(NeighborCells*)local.copied = *(NeighborCells*)local.neighbors;
    for (int i = 0; i < 6; ++i) {
        unsigned index = local.copied[i];
        if (index >= 81) continue;
        if (!remaining) {
            int blocked = grid[index] >= 242 ? 1 : 0;
            if (blocked) continue;
        }
        if (depth < limit) BattleGrid_PaintFootprintAfterClearance(grid, index, value, limit, remaining, depth);
        if (!remaining && index < 81) grid[index] = value;
    }
}
