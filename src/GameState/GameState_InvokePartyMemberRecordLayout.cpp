#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
#pragma optimization_level 4
// Original data: arm9/main @ 0x20fdcb0; symbol: data_020fdcb0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char GraphicsSelectObjectRatioColor_UnknownRoleZeroInitializedStorage[];
extern "C" void PartyStatus_DrawMemberValueDigitsAndBar(void *, void *, int, int, unsigned int, int, int, int, int, int, int, int);
// Original: arm9/main @ 0x0201FD38; symbol: func_0201fd38; size: 0x98.
extern "C" void GameState_InvokePartyMemberRecordLayout(void *param1, void *param2, int index) {
    GameState *state = GameState::GetInstance();
    if (state->GetPartyMemberByIndex(index) == 0) return;
    unsigned char *entry = GraphicsSelectObjectRatioColor_UnknownRoleZeroInitializedStorage + index * 0x20;
    int value = *(int *)(entry + 4);
    if (value < 0) return;
    PartyStatus_DrawMemberValueDigitsAndBar(param1, param2, index, value, *(unsigned int *)(entry + 0xc), 0x30, 0x1c, 7, 0x24, 0xb, 0xc, 1);
}
