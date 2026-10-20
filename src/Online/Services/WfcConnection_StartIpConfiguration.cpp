#include <globaldefs.h>
ARM
extern "C" void *Network_GetConnectionWorkspace(unsigned mask);
extern "C" void WfcConnection_BuildSelectedProfileIpSettings(void *first, void *state, void *fourth);
extern "C" int Network_ConfigureSharedWorkWithSwappedWords(void *state);
extern "C" void GameState_SetSelectedStateWordFields(unsigned mode);
// Original data: arm9/ov031 @ 0x224e1c0; symbol: data_ov031_0224e1c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned NetworkInitializeSocketStack_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02215358; symbol: func_ov031_02215358; size: 0x64.
extern "C" int WfcConnection_StartIpConfiguration(void *state) {
    void *first = Network_GetConnectionWorkspace(1);
    void *fourth = Network_GetConnectionWorkspace(4);
    WfcConnection_BuildSelectedProfileIpSettings(first, state, fourth);
    NetworkInitializeSocketStack_UnknownRoleZeroInitializedStorage = 4;
    if (!Network_ConfigureSharedWorkWithSwappedWords(fourth)) return 12;
    GameState_SetSelectedStateWordFields(2);
    return 17;
}
