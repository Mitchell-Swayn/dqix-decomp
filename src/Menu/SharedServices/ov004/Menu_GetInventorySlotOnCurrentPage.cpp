#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
extern "C" void* Menu_FindInventoryGridByKey(void*, unsigned);
// Original: arm9/ov004 @ 0x021570A4; symbol: Menu_GetInventorySlotOnCurrentPage; size: 0x4C.
// Selects a 40-byte shared-state entry by the type-seven object's signed row and six-column index.
// The record fields and the semantic role of this table remain unknown.
extern "C" void* Menu_GetInventorySlotOnCurrentPage(void* self, unsigned column) {
    if (column >= 6) return 0;
    char* state = (char*)GameState::GetInstance() + 0x5e6c;
    char* object = (char*)Menu_FindInventoryGridByKey(self, 0x5b);
    int index = *(short*)(object + 0x5c) * (short)6 + column;
    return state + 4 + index * 40;
}
