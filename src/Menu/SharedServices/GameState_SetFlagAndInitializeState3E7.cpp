#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void GameState_WriteUnknownF70(void*, unsigned);
extern "C" void Menu_QueueScriptEntry(void*, unsigned);
// Original data: arm9/ov004 @ 0x2171034; symbol: data_ov004_02171034.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned char InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov004 @ 0x0216E8B4; symbol: func_ov004_0216e8b4; size: 0x3C.
extern "C" int GameState_SetFlagAndInitializeState3E7(void* self) {
    InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage[2] = 1;
    void* state = _ZN9GameState11GetInstanceEv();
    GameState_WriteUnknownF70(state, 0);
    Menu_QueueScriptEntry(self, 0x3e7);
    return 0;
}
