#include <globaldefs.h>
ARM
#pragma force_active on
// Retain original presentation entries while some callers remain in weak-reference fallback objects.
struct ActorId { unsigned char prefix[4]; short id; inline int GetId() const { return id; } };
struct Bystander { unsigned char id; unsigned char padding[3]; int moved; unsigned char* actor; };
extern "C" unsigned CombatantMotion_GetReservedGridCell(unsigned char*);
extern "C" unsigned GameObject_GetBattleGridIndexOrInvalid(unsigned char*);
extern "C" void CombatantMotion_SetReservedGridCell(int, unsigned char);
// Original: arm9/ov025 @ 0x021e1ff4; symbol: func_ov025_021e1ff4; size: 0xe4.
// Blocks supplied cells and invalidates matching bystander reservations while preserving the two active actors.
extern "C" void BattleGrid_BlockCellsAndRelocateBystanders(const unsigned char* cells, int cellCount, unsigned char* grid,
    ActorId* first, ActorId* second, Bystander* bystanders, int bystanderCount)
{
    if (!first || !second) return;
    for (int i = 0; i < cellCount; ++i) {
        unsigned cell = cells[i];
        if (cell >= 81) continue;
        if (cell < 81) grid[cell] = 255;
        for (int j = 0; j < bystanderCount; ++j) {
            unsigned char* actor = bystanders[j].actor;
            if (bystanders[j].id != first->GetId() && bystanders[j].id != second->GetId()) {
            int reserved = CombatantMotion_GetReservedGridCell(actor);
            if (reserved >= 81) reserved = GameObject_GetBattleGridIndexOrInvalid(actor);
            if (reserved == cells[i]) {
                bystanders[j].moved = 1;
                CombatantMotion_SetReservedGridCell((int)actor, 255);
            }
            }
        }
    }
}
