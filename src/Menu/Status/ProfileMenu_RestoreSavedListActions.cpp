#include <globaldefs.h>
ARM
extern "C" void GameState_ClearMaskFromKeyedEntry(void*, unsigned, unsigned);
extern "C" void GameState_AppendValueAndSetNodeFlags(void*, unsigned, unsigned);
extern "C" void Menu_QueueScriptEntry(void*, unsigned);
// Original data: arm9/ov004 @ 0x2171030; symbol: data_ov004_02171030.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" void* MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov004 @ 0x02169ADC; symbol: func_ov004_02169adc; size: 0x70.
extern "C" int ProfileMenu_RestoreSavedListActions(void* self) {
    GameState_ClearMaskFromKeyedEntry(self, 0x1e, 0x18);
    GameState_ClearMaskFromKeyedEntry(self, 0x1f, 0x18);
    GameState_AppendValueAndSetNodeFlags(self, 2, 8);
    void* state = *(void**)((char*)MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage + 0x190);
    if (state == 0) return 0;
    if (*(unsigned char*)state != 0) Menu_QueueScriptEntry(self, 0x48);
    return 0;
}
